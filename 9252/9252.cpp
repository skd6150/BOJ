#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int aLen, bLen, len;
    string a, b;
    cin >> a >> b;
    aLen = a.length();
    bLen = b.length();
    pair<int, int> pos = make_pair(aLen, bLen);
    vector<vector<int>> dp(aLen+1, vector<int>(bLen+1));
    vector<char> res;
    for(int i=1; i<=aLen; i++) {
        for(int j=1; j<=bLen; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    len = dp[aLen][bLen];
    cout << len << endl;
    while(len > 0 && pos.first >= 0 && pos.second >= 0) {
        if(a[pos.first-1] == b[pos.second-1]) {
            len--;
            res.push_back(a[pos.first-1]);
            pos.first--;
            pos.second--;
        }
        else {
            if(dp[pos.first-1][pos.second] > dp[pos.first][pos.second-1]) pos.first--;
            else pos.second--;
        }
    }
    for(int i=res.size()-1; i>=0; i--) cout << res[i];
    cout << endl;
}