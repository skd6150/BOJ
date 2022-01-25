#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    for(int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from-1].push_back(make_pair(to-1, cost));
        adj[to-1].push_back(make_pair(from-1, cost));
    }
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(auto vertex: adj[here]) {
            int there = vertex.first;
            int nextCost = cost + vertex.second;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push(make_pair(nextCost, there));
            }
        }
    }
    cout << dist[n-1] << endl;
}