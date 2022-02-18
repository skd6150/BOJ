#include <iostream>
#include <vector>
using namespace std;

int dfs(int y, int x, int width, vector<vector<int>>& field, vector<vector<int>>& dp) {
    int res = 1;
    vector<pair<int, int>> diff = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
    for(pair<int, int> d: diff) {
    pair<int, int> next = make_pair(y + d.first, x + d.second);
        if(next.first < 0 || next.first >= width) continue;
        if(next.second < 0 || next.second >= width) continue;
        if(field[y][x] >= field[next.first][next.second]) continue;
        if(dp[next.first][next.second] != 0) res = max(res, dp[next.first][next.second] + 1);
        else res = max(res, dfs(next.first, next.second, width, field, dp) + 1);
    }
    return dp[y][x] = res;
}

int main() {
    int n, res = -1;
    scanf("%d", &n);
    vector<vector<int>> field(n);
    vector<vector<int>> dp(n);
    for(int i=0; i<n; i++) {
        field[i].resize(n);
        dp[i].resize(n);
        for(int j=0; j<n; j++) {
            scanf("%d", &field[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] != 0) continue;
            dfs(i, j, n, field, dp);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            res = max(res, dp[i][j]);
        }
    }

    printf("%d", res);
}