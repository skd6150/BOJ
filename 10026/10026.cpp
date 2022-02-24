#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(pair<int, int> pos, int n, vector<string>& pic, vector<vector<bool>>& check) {
    check[pos.first][pos.second] = true;
    // cout << pos.first << " " << pos.second << endl;
    vector<pair<int, int>> diff = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
    for(pair<int, int> d: diff) {
        pair<int, int> next = make_pair(pos.first + d.first, pos.second + d.second);
        if(next.first >= n || next.first < 0) continue;
        if(next.second >= n || next.second < 0) continue;
        if(check[next.first][next.second]) continue;
        if(pic[pos.first][pos.second] == pic[next.first][next.second]) {
            bfs(next, n, pic, check);
        }
    }
}

int main() {
    int n, res = 0;
    cin >> n;
    vector<string> pic;
    vector<vector<bool>> check(n);
    for(int i=0; i<n; i++) {
        check[i].resize(n);
        for(int j=0; j<n; j++) check[i][j] = false;
    }
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        pic.push_back(tmp);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(check[i][j]) continue;
            bfs(make_pair(i, j), n, pic, check);
            res++;
        }
    }
    cout << res << " ";
    for(int i=0; i<n; i++) {
        check[i].resize(n);
        for(int j=0; j<n; j++) check[i][j] = false;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(pic[i][j] == 'R') pic[i][j] = 'G';
        }
    }
    res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(check[i][j]) continue;
            bfs(make_pair(i, j), n, pic, check);
            res++;
        }
    }
    cout << res << endl;
}