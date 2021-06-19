#include <iostream>
using namespace std;

int dst[100100];
int dp[100100][5];

int min(int a, int b) {
	if(a == -1) return b;
	return a < b ? a : b;
}

int cost(int from, int to) {
	if(from == to) return 1;
	if(from == 0 || to == 0) return 2;
	if((from + to)%2 == 0) return 4;
	else return 3;
}

int main() {
	int length = 0, res = 987654321;
	while(true) {
		cin >> dst[length++];
		if(dst[length-1] == 0) {
			length--;
			break;
		}
	}
	dp[0][0] = cost(0, dst[0]);
	
	for(int i=1; i<length; i++) {
		for(int j=0; j<5; j++) {
			if(dp[i-1][j] == 0) continue;
			if(dst[i] != j) {
				if(dp[i][j] == 0) dp[i][j] = dp[i-1][j] + cost(dst[i-1], dst[i]);
				else dp[i][j] = min(dp[i][j], dp[i-1][j] + cost(dst[i-1], dst[i]));	
			}
			if(dst[i] != dst[i-1]) {
				if(dp[i][dst[i-1]] == 0) dp[i][dst[i-1]] = dp[i-1][j] + cost(j, dst[i]);
				else dp[i][dst[i-1]] = min(dp[i][dst[i-1]], dp[i-1][j] + cost(j, dst[i]));	
			}
		}
	}
	for(int i=0; i<5; i++) {
		if(dp[length-1][i] != 0 && dp[length-1][i] < res) res = dp[length-1][i];
	}
	cout << res << endl;
}