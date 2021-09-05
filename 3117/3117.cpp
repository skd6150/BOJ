#include <iostream>
#include <vector>
using namespace std;

int N, K, M;
int init[100100];
int dp[100100][33];

int main() {
	cin >> N >> K >> M;
	for(int i=1; i<=N; i++) {
		cin >> init[i];
	}
	for(int i=1; i<=K; i++) {
		cin >> dp[i][0];
	}
	
	for(int j=1; j<=30; j++) {
		for(int i=1; i<=K; i++) {
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
	
	for(int i=1; i<=N; i++) {
		int remainTime = M;
		int videoIdx = init[i];
		for(int j=30; j>=0; j--) {
			if((1<<j) < remainTime) {
				remainTime -= 1 << j;
				videoIdx = dp[videoIdx][j];
			}
		}
		cout << videoIdx << " ";
	}
}