#include <iostream>
#include <vector>
#include <queue>
#define LL long long int
#define INF 9876543210
using namespace std;

LL dfs(int idx, vector<LL>& dist, vector<LL>& count, vector<vector<pair<LL, int>>>& edges) {
    if(idx == 2) return 1;
    if(count[idx] == -1) {
        count[idx] = 0;
        for(pair<int, int> next: edges[idx]) {
            if(dist[idx] <= dist[next.second]) continue;
            count[idx] += dfs(next.second, dist, count, edges);
        }
    }
    return count[idx];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<LL> dist(n+1, INF), count(n+1, -1);
    vector<vector<pair<LL, int>>> edges(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(c, b));
        edges[b].push_back(make_pair(c, a));
    }
    priority_queue<pair<LL, int>> pq;
    pq.push(make_pair(0, 2));
    dist[2] = 0;
    while(!pq.empty()) {
        LL cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(pair<LL, int> next: edges[cur]) {
            if(cost+next.first >= dist[next.second]) continue;
            dist[next.second] = cost+next.first;
            pq.push(make_pair(-(cost+next.first), next.second));
        }
    }
    cout << dfs(1, dist, count, edges) << endl;
}