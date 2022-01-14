#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
    int a;
    int b;
    int cost;
};

bool cmpEdge(edge a, edge b) {
    return a.cost < b.cost;
}

int find(int vertex, vector<int>& disjoint) {
    if(disjoint[vertex] == vertex) return vertex;
    return disjoint[vertex] = find(disjoint[vertex], disjoint);
}

void merge(int vertexA, int vertexB, vector<int>& disjoint) {
    int findA = find(vertexA, disjoint);
    int findB = find(vertexB, disjoint);
    if(findA == findB) return;
    else {
        disjoint[findA] = findB;
    }
}

int main() {
    int n, m;
    long long int total = 0;
    vector<int> disjoint;
    vector<edge> edges;
    cin >> n >> m;
    edges.resize(m);
    for(int i=0; i<n+1; i++) disjoint.push_back(i);
    for(int i=0; i<m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges[i] = {a, b, cost};
    }
    sort(edges.begin(), edges.end(), cmpEdge);
    for(int i=0; i<m; i++) {
        edge cur = edges[i];
        // cout << cur.a << " " << cur.b << " " << cur.cost << endl;
        if(find(cur.a, disjoint) == find(cur.b, disjoint)) continue;
        else {
            total += cur.cost;
            merge(cur.a, cur.b, disjoint);
            // for(int i=0; i<n; i++) cout << disjoint[i] << " ";
            // cout << endl;
        }
    }

    cout << total << endl;
}