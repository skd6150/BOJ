#include <iostream>
#include <vector>
using namespace std;

int find(int idx, vector<int>& parents) {
    if(idx == parents[idx]) return idx;
    else return parents[idx] = find(parents[idx], parents);
}

void merge(int idxA, int idxB, vector<int>& parents) {
    int rootA = find(idxA, parents);
    int rootB = find(idxB, parents);
    if(rootA == rootB) return;
    else parents[rootA] = rootB;
}

int main() {
    int n, m;
    bool flag = false;
    cin >> n >> m;
    vector<int> parents(n);
    for(int i=0; i<n; i++) parents[i] = i;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if(find(a, parents) == find(b, parents)) {
            cout << i << endl;
            flag = true;
            break;
        }
        merge(a, b, parents);
    }
    if(!flag) cout << 0 << endl;
}