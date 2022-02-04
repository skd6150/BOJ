#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define INF 987654321
using namespace std;

int width, height;

pair<int, int> convert(int idx) {
    return make_pair(idx/width, idx%width);
}

int convert(pair<int, int> pos) {
    return pos.first * width + pos.second;
}

int main() {
    cin >> width >> height;
    vector<vector<int>> field(height), dist;
    for(int i=0; i<height; i++) {
        dist.push_back(vector<int>(width, INF));
    }
    for(int i=0; i<height; i++) {
        string str;
        cin >> str;
        for(char c: str) field[i].push_back(c);
    }

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    dist[0][0] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> here = convert(pq.top().second);
        pq.pop();
        if(dist[here.first][here.second] < cost) continue;
        vector<pair<int, int>> adj;
        if(here.first - 1 >= 0) {
            adj.push_back(make_pair(here.first - 1, here.second));
        }
        if(here.first + 1 < height) {
            adj.push_back(make_pair(here.first + 1, here.second));
        }
        if(here.second - 1 >= 0) {
            adj.push_back(make_pair(here.first, here.second - 1));
        }
        if(here.second + 1 < width) {
            adj.push_back(make_pair(here.first, here.second + 1));
        }

        for(auto there: adj) {
            int nextCost = cost;
            if(field[there.first][there.second] == '1') nextCost++;
            if(dist[there.first][there.second] > nextCost) {
                dist[there.first][there.second] = nextCost;
                pq.push(make_pair(-nextCost, convert(there)));
            }
        }
    }

    // cout << endl;
    // for(auto row: dist) {
    //     for(int cost: row) {
    //         cout << cost << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist[height-1][width-1] << endl;
}