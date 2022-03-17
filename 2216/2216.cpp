#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b, c, xLen, yLen;
    string x, y;
    cin >> a >> b >> c;
    cin >> x >> y;
    xLen = x.length();
    yLen = y.length();
    vector<vector<int>> dp(yLen+1, vector<int>(xLen+1));
    for(int i=0; i<=yLen; i++) dp[i][0] = i*b;
    for(int i=0; i<=xLen; i++) dp[0][i] = i*b;

    for(int i=1; i<=yLen; i++) {
        for(int j=1; j<=xLen; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + b;
            if(y[i-1] == x[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a);
            else {
                if(b*2 < c) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + c);
                else dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2*b);
            }
        }
    }

    for(int i=0; i<=yLen; i++) {
        for(int j=0; j<=xLen; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[yLen][xLen] << endl;
}