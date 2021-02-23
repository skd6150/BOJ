#include <iostream>
using namespace std;

int max(int a, int b) {
	return (a>b) ? a : b;
}

int main() {
	int N, K;
	int weight, value, bag[100001] = {0,};
	cin >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> weight >> value;
		for(int j=K; j>=weight; j--) {
			bag[j] = max(bag[j], bag[j-weight]+value);
		}
	}
	cout << bag[K] << endl;
}