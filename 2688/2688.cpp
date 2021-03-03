#include <iostream>
using namespace std;

long long int dp[65][10];

int main() {
	for(int i=0; i<10; i++) dp[1][i] = 1;
	for(int i=2; i<=64; i++) {
		for(int j=0; j<10; j++) {
			long long int& cur = dp[i][j];
			for(int k=0; k<=j; k++) {
				cur += dp[i-1][k];
			}
		}
	}
	
	int T;
	cin >> T;
	while(T--) {
		int n;
		long long int res = 0;
		cin >> n;
		for(int i=0; i<10; i++) res += dp[n][i];
		cout << res << endl;
	}
}