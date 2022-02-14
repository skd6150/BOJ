#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int main() {
    int n, res = MAX;
    cin >> n;
    vector<vector<int>> cost;
    for(int i=0; i<n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        cost.push_back({r, g, b});
    }
    for(int i=0; i<3; i++) {
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++) {
            dp[i].resize(3);
        }
        dp[0] = cost[0];
        for(int j=0; j<3; j++) {
            if(i != j) dp[0][j] = MAX;
        }
        for(int j=1; j<n; j++) {
            dp[j][0] = cost[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = cost[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = cost[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }
        for(int j=0; j<3; j++) {
            if(i != j) res = min(res, dp[n-1][j]);
        }
    }
    cout << res << endl;
}