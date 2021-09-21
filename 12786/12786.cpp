#include <iostream>
#define MAX 987654321
using namespace std;

bool route[110][22];
int dp[110][22];

int min(int a, int b) {
	return a > b ? b : a;
}
bool movable(int a, int b) {
	return (a-b > 0 ? a-b : b-a) <= 1 || b+1 == (a+1)*2 || ((a+1)>=10 && b+1==20);
}

int main() {
	for(int i=0; i<110; i++) for(int j=0; j<22; j++) dp[i][j] = MAX;
	int N, T, res=MAX;
	cin >> N >> T;
	for(int i=0; i<N; i++) {
		int numRoute;
		cin >> numRoute;
		for(int j=0; j<numRoute; j++) {
			int r;
			cin >> r;
			route[i][r-1] = true;
		}
	}
	
	for(int i=0; i<20; i++) {
		if(!route[0][i]) continue;
		if(i == 0 || i == 1) dp[0][i] = 0;
		else dp[0][i] = 1;
	}
	
	for(int i=0; i<N-1; i++) {
		for(int j=0; j<20; j++) {
			if(!route[i][j]) continue;
			for(int k=0; k<20; k++) {
				if(!route[i+1][k]) continue;
				if(movable(j, k)) dp[i+1][k] = min(dp[i+1][k], dp[i][j]);
				else dp[i+1][k] = min(dp[i+1][k], dp[i][j]+1);
			}
		}
	}
	
	for(int i=0; i<20; i++) {
		res = min(res, dp[N-1][i]);
	}
	cout << ((res <= T) ? res : -1) << endl;
}