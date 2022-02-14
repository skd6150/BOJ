#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ranks(n);
    vector<int> result;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        ranks[b-1]++;
    }
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        if(ranks[i] == 0) pq.push(-i);
    }
    while(!pq.empty()) {
        int cur = -pq.top();
        pq.pop();
        result.push_back(cur);
        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i];
            ranks[next]--;
            if(ranks[next] == 0) pq.push(-next);
        }
    }
    for(int n: result) cout << n+1 << " ";
    cout << endl;
}