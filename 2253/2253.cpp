#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 200
using namespace std;

int main() {
    int n, m, res = INF;
    cin >> n >> m;
    vector<int> arr;
    vector<vector<int>> dp;
    for(int i=0; i<n+1; i++) {
        dp.push_back(vector<int>(200, INF));
    }
    dp[1][1] = 0;
    dp[2][1] = 1;
    for(int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 2) {
            cout << -1 << endl;
            return 0;
        }
        arr.push_back(tmp);
    }

    for(int i=3; i<=n; i++) {
        bool flag = false;
        for(int loc: arr) {
            if(loc == i) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        for(int j=1; j<min(i, MAX)-1; j++) {
            dp[i][j] = min(dp[i-j][j-1], min(dp[i-j][j], dp[i-j][j+1])) + 1;
        }
    }
    for(int i=1; i<min(n, MAX); i++) {
        res = min(res, dp[n][i]);
    }
    if(res >= INF) cout << -1 << endl;
    else cout << res << endl;
}