#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
    int from, to, cost;
};

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

int find(int idx, vector<int>& parents) {
    if(parents[idx] == idx) return idx;
    return parents[idx] = find(parents[idx], parents);
}

void merge(int idxA, int idxB, vector<int>& parents) {
    int parentA = find(idxA, parents);
    int parentB = find(idxB, parents);
    if(parentA == parentB) return;
    else parents[parentA] = parentB;
}

int main() {
    int v, e, result = 0;
    cin >> v >> e;
    vector<int> parents(v+10);
    vector<edge> edges;
    for(int i=1; i<=v; i++) parents[i] = i;
    for(int i=0; i<e; i++) {
        edge tmp;
        cin >> tmp.from >> tmp.to >> tmp.cost;
        edges.push_back(tmp);
    }
    sort(edges.begin(), edges.end(), cmp);
    for(edge cur: edges) {
        if(find(cur.from, parents) == find(cur.to, parents)) continue;
        else {
            result += cur.cost;
            merge(cur.from, cur.to, parents);
        }
    }
    cout << result << endl;
}