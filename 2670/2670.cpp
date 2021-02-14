#include <iostream>

using namespace std;

double max(double a, double b) {
	return (a > b) ? a : b;
}

int main() {
	double dp[10001];
	double res = 0;
	int N;
	
	cin >> N;
	for(int i=0; i<N; i++) cin >> dp[i];
	
	for(int i=0; i<N; i++) {
		res = max(res, dp[i]);
	}
	
	for(int i=1; i<N; i++) {
		dp[i] = max(dp[i], dp[i] * dp[i-1]);
		res = max(dp[i], res);
	}
	
	
	cout << fixed;
	cout.precision(3);
	cout << res << endl;
}