#include <iostream>
using namespace std;

int dp[200200][19];

int main() {
	int M, Q;
	//cin >> M;
	scanf("%d", &M);
	//for(int i=1; i<=M; i++) cin >> dp[i][0];
	for(int i=1; i<=M; i++) scanf("%d", &dp[i][0]);
	for(int i=1; i<=18; i++) {
		for(int j=1; j<=M; j++) {
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
	cin >> Q;
	while(Q--) {
		int n, x;
		//cin >> n >> x;
		scanf("%d %d", &n, &x);
		
		for(int i=18; i>=0; i--) {
			if((1<<i) <= n) {
				n -= (1<<i);
				x = dp[x][i];
			}
		}
		//cout << x << endl;
		printf("%d\n", x);
	}
}