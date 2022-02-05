#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

pair<int, int> convert(int idx) {
    return make_pair(idx/501, idx%501);
}

int convert(pair<int, int> pos) {
    return pos.first*501 + pos.second;
}

int main() {
    int n, m;
    vector<vector<int>> field, dist;
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<=500; i++) {
        field.push_back(vector<int>(501, 0));
        dist.push_back(vector<int>(501, INF));
    }
    cin >> n;
    for(int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                field[j][i] = 1;
            }
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                field[j][i] = INF;
            }
        }
    }
    
    pq.push(make_pair(0, 0));
    dist[0][0] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> here = convert(pq.top().second);
        pq.pop();
        // cout << here.first << " " << here.second << endl;
        if(dist[here.first][here.second] < cost) continue;
        vector<pair<int, int>> next;
        if(here.first-1 >= 0) {
            next.push_back(make_pair(here.first-1, here.second));
        }
        if(here.first+1 <= 500) {
            next.push_back(make_pair(here.first+1, here.second));
        }
        if(here.second-1 >= 0) {
            next.push_back(make_pair(here.first, here.second-1));
        }
        if(here.second+1 <= 500) {
            next.push_back(make_pair(here.first, here.second+1));
        }
        for(auto there: next) {
            int nextCost = cost + field[there.first][there.second];
            if(dist[there.first][there.second] <= nextCost) continue;
            dist[there.first][there.second] = nextCost;
            pq.push(make_pair(-nextCost, convert(there)));
        }
    }
    if(dist[500][500] >= INF) cout << -1 << endl;
    else cout << dist[500][500] << endl;
}