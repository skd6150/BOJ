#include <iostream>
#include <vector>
#include <bitset>
#define N 440
using namespace std;

bitset<N> dfs(int idx, vector<vector<int>>& edges, vector<bitset<N>>& histories) {
    histories[idx].set(idx);
    if(edges[idx].size() == 0) {
        return histories[idx];
    }
    for(int next: edges[idx]) {
        if(histories[next].any()) {
            histories[idx] |= histories[next];
        }
        else {
            histories[idx] |= dfs(next, edges, histories);
        }
    }
    return histories[idx];
}

int main() {
    int n, k, q;
    scanf("%d %d", &n, &k);
    vector<bitset<N>> histories(n+1);
    vector<vector<int>> edges(n+1);
    for(int i=0; i<k; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from].push_back(to);
    }
    for(int i=1; i<=n; i++) {
        if(histories[i].none()) dfs(i, edges, histories);
    }
    cin >> q;
    for(int i=0; i<q; i++) {
        int a, b;
        bool atob, btoa;
        scanf("%d %d", &a, &b);
        atob = histories[a][b];
        btoa = histories[b][a];
        if(!atob && !btoa) printf("0\n");
        else {
            if(atob) printf("-1\n");
            else printf("1\n");
        }
    }
}