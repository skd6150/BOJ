#include <iostream>
using namespace std;

int gallery[202][2];
int dp[222][222][3];

int max(int a, int b, int c = -1) {
	return (a>b ? a : b) > c ? (a>b ? a : b) : c;
}

int main() {
	int N, block;
	cin >> N >> block;
	for(int i=0; i<=N; i++) {
		cin >> gallery[i][0] >> gallery[i][1];
	}
	
	dp[0][0][0] = gallery[0][0] + gallery[0][1];
	dp[0][1][1] = gallery[0][1];
	dp[0][1][2] = gallery[0][0];
	
	for(int i=1; i<N; i++) {
		for(int k=0; k<=block && k<=i; k++) {
			dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1], dp[i-1][k][2]) + gallery[i][0] + gallery[i][1];
			dp[i][k+1][1] = max(dp[i-1][k][0], dp[i-1][k][1]) + gallery[i][1];
			dp[i][k+1][2] = max(dp[i-1][k][0], dp[i-1][k][2]) + gallery[i][0];
		}
	}
	cout << max(dp[N-1][block][0], dp[N-1][block][1], dp[N-1][block][2]) << endl;
}