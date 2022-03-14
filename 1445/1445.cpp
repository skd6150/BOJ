#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 10000
using namespace std;

int main() {
    int h, w;
    pair<int, int> S, F;
    vector<pair<int, int>> diff = {make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};
    vector<pair<int, int>> garbage;
    cin >> h >> w;
    vector<vector<int>> field(h, vector<int>(w)), check(h, vector<int>(w, -1));
    for(int i=0; i<h; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<w; j++) {
            if(tmp[j] == 'g') {
                for(pair<int, int> d: diff) {
                    pair<int, int> next = make_pair(i+d.first, j+d.second);
                    if(next.first < 0 || next.first >= h) continue;
                    if(next.second < 0 || next.second >= w) continue;
                    field[next.first][next.second] = 1;
                }
                garbage.push_back(make_pair(i,j));
            }
            else if(tmp[j] == 'S') S = make_pair(i, j);
            else if(tmp[j] == 'F') F = make_pair(i, j);
        }
    }
    for(pair<int, int> g: garbage) field[g.first][g.second] = INF;
    field[S.first][S.second] = 0;
    field[F.first][F.second] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-field[S.first][S.second], S));
    check[S.first][S.second] = field[S.first][S.second];
    while(!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> pos = pq.top().second;
        pq.pop();
        for(pair<int, int> d: diff) {
            pair<int, int> next = make_pair(pos.first+d.first, pos.second+d.second);
            if(next.first < 0 || next.first >= h) continue;
            if(next.second < 0 || next.second >= w) continue;
            if(check[next.first][next.second] != -1) continue;
            check[next.first][next.second] = cost + field[next.first][next.second];
            pq.push(make_pair(-check[next.first][next.second], next));
        }
    }
    cout << check[F.first][F.second] / INF << " " << check[F.first][F.second] % INF << endl;
}