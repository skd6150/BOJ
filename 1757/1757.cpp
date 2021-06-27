#include <iostream>
using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int N, M;
int input[11000];
int dp[11000][550];

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> input[i];
	
	dp[0][0] = 0;
	for(int i=0; i<N; i++) {
		for(int j=1; j<=M; j++) {
			if(i+j < 11000)dp[i+j][j] = dp[i+j-1][j-1] + input[i+j-1];
			if(i+2*j < 11000) dp[i+2*j][0] = max(dp[i+2*j][0], dp[i+j][j]);
		}
		dp[i+1][0] = max(dp[i][0], dp[i+1][0]);
	}
	
	cout << dp[N][0] << endl;
	
	// for(int i=0; i<=N; i++) {
	// 	for(int j=0; j<=M; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}