#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> diff = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

int dfs(int y, int x, int h, int w, int sum, int depth, pair<int, int> before, vector<vector<int>>& field) {
    int res = 0;
    if(depth == 3) {
        return sum + field[y][x];
    }
    if(depth == 1) {
        for(int i=0; i<4; i++) {
            for(int j=i+1; j<4; j++) {
                bool flag = false;
                pair<int, int> next[2] = {make_pair(y+diff[i].first,x+diff[i].second), make_pair(y+diff[j].first,x+diff[j].second)};
                for(int k=0; k<2; k++) {
                    if(next[k] == before) flag = true;
                    if(next[k].first < 0 || next[k].first >= h) flag = true;
                    if(next[k].second < 0 || next[k].second >= w) flag = true;
                }
                if(flag) continue;
                res = max(res, sum + field[y][x] + field[next[0].first][next[0].second] + field[next[1].first][next[1].second]);
            }
        }
    }
    for(pair<int, int> d: diff) {
        pair<int, int> next = make_pair(y+d.first, x+d.second);
        if(next == before) continue;
        if(next.first < 0 || next.first >= h) continue;
        if(next.second < 0 || next.second >= w) continue;
        res = max(res, dfs(next.first, next.second, h, w, sum + field[y][x], depth+1, make_pair(y, x), field));
    }
    return res;
}

int main() {
    int h, w, res = 0;
    cin >> h >> w;
    vector<vector<int>> field(h, vector<int>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> field[i][j];
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            res = max(res, dfs(i, j, h, w, 0, 0, make_pair(-1, -1), field));
        }
    }
    cout << res << endl;
}