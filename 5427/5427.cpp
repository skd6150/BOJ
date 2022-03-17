#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 987654321
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> diff = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
    while(t--) {
        int h, w;
        int res = -1;
        cin >> w >> h;
        vector<vector<char>> field(h, vector<char>(w));
        vector<vector<int>> timelimit(h, vector<int>(w, INF));
        vector<vector<int>> check(h, vector<int>(w, INF));
        queue<pair<pair<int, int>, int>> player;
        queue<pair<pair<int, int>, int>> fire;
        for(int i=0; i<h; i++) {
            string str;
            cin >> str;
            for(int j=0; j<w; j++) {
                char tmp = str[j];
                if(tmp == '@') {
                    player.push(make_pair(make_pair(i, j), 0));
                    check[i][j] = 0;
                }
                if(tmp == '*') {
                    fire.push(make_pair(make_pair(i, j), 0));
                    timelimit[i][j] = 0;
                }
                if(tmp != '#' && (i == 0 || i == h-1 || j == 0 || j == w-1)) field[i][j] = 'E';
                else field[i][j] = tmp;
            }
        }
        while(!fire.empty()) {
            pair<int, int> cur = fire.front().first;
            int time = fire.front().second;
            fire.pop();
            for(pair<int, int> d: diff) {
                pair<int, int> next = make_pair(cur.first + d.first, cur.second + d.second);
                if(next.first < 0 || next.first >= h) continue;
                if(next.second < 0 || next.second >= w) continue;
                if(field[next.first][next.second] == '#') continue;
                if(timelimit[next.first][next.second] != INF) continue;
                timelimit[next.first][next.second] = time+1;
                fire.push(make_pair(next, time+1));
            }
        }
        while(!player.empty()) {
            pair<int, int> cur = player.front().first;
            int time = player.front().second;
            if(field[cur.first][cur.second] == 'E') {
                res = time;
                break;
            }
            player.pop();
            for(pair<int, int> d: diff) {
                pair<int, int> next = make_pair(cur.first + d.first, cur.second + d.second);
                if(next.first < 0 || next.first >= h) continue;
                if(next.second < 0 || next.second >= w) continue;
                if(field[next.first][next.second] == '#') continue;
                if(check[next.first][next.second] != INF) continue;
                if(timelimit[next.first][next.second] <= time+1) continue;
                check[next.first][next.second] = time+1;
                player.push(make_pair(next, time+1));
            }
        }
        if(res == -1) cout << "IMPOSSIBLE" << endl;
        else cout << res+1 << endl;
    }
}