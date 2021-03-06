#include <iostream>
#include <string>
using namespace std;

int dp[1011][1011];

int max(int a, int b) {
	return (a>b) ? a : b;
}

int main() {
	string a, b;
	cin >> a >> b;
	
	for(int i=1; i<=a.size(); i++) {
		for(int j=1; j<=b.size(); j++) {
			char aChar = a[i-1];
			char bChar = b[j-1];
			if(aChar == bChar) dp[i][j] = dp[i-1][j-1] + 1;
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	for(int i=0; i<=a.size(); i++) {
		for(int j=0; j<=b.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << dp[a.size()][b.size()] << endl;
}