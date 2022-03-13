#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> diff = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

int dfs(int y, int x, int h, int w, vector<vector<int>>& check, vector<vector<int>>& vertex) {
    //cout << y << " " << x << endl;
    if(y==h-1 && x==w-1) {
        return check[y][x] = 1;
    }
    else if(check[y][x] == -1) {
        check[y][x] = 0;
        for(pair<int, int> d: diff) {
            pair<int, int> next = make_pair(y + d.first, x + d.second);
            if(next.first < 0 || next.first >= h) continue;
            if(next.second < 0 || next.second >= w) continue;
            if(vertex[y][x] <= vertex[next.first][next.second]) continue;
            check[y][x] += dfs(next.first, next.second, h, w, check, vertex);
        }
    }
    return check[y][x];
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> vertex(h, vector<int>(w));
    vector<vector<int>> check(h, vector<int>(w, -1));
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> vertex[i][j];
        }
    }

    cout << dfs(0, 0, h, w, check, vertex) << endl;

    // for(int i=0; i<h; i++) {
    //     for(int j=0; j<w; j++) {
    //         cout << check[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}