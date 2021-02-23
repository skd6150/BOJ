#include <iostream>
using namespace std;

int max(int a, int b) {
	return (a>b) ? a : b;
}

struct item {
	int weight;
	int value;
};

int N, K, res = -1;
item items[101];
int bag[111][100011]; //bag[item][weight] -> item번까지의 물품을 검사했을때 weight무게 배낭의 가치 최대값

int main() {
	cin >> N >> K;
	
	for(int i=0; i<N; i++) {
		cin >> items[i].weight >> items[i].value;
	}
	
	for(int i=0; i<N; i++) {
		int weight = items[i].weight;
		int value = items[i].value;
		
		bag[i][weight] = max(bag[i][weight], value);
		if(i == 0) continue;
		
		for(int j=0; j<=K; j++) {
			bag[i][j] = max(bag[i-1][j], bag[i][j]);
			if(j-weight >= 0) {
				bag[i][j] = max(bag[i][j], bag[i-1][j-weight] + value);
			}
		}
	}
	
	// for(int i=0; i<N; i++) {
	// 	for(int j=0; j<=K; j++) {
	// 		cout << bag[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	for(int i=0; i<=K; i++) {
		res = max(bag[N-1][i], res);
	}
	cout << res << endl;
}