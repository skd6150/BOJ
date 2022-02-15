#include <iostream>
#include <vector>
using namespace std;

int find(int idx, vector<int>& parents) {
    if(parents[idx] == idx) return idx;
    else return parents[idx] = find(parents[idx], parents);
}

void merge(int idxA, int idxB, vector<int>& parents) {
    int treeA = find(idxA, parents);
    int treeB = find(idxB, parents);
    if(treeA == treeB) return;
    else parents[treeA] = treeB;
}

int main() {
    int g, p, res = 0;
    cin >> g >> p;
    vector<int> arr, parents(g+1);
    for(int i=0; i<=g; i++) parents[i] = i;
    for(int i=0; i<p; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for(int plane: arr) {
        int gate = find(plane, parents);
        if(gate == 0) break;
        else {
            res++;
            merge(gate, gate-1, parents);
        }
    }
    cout << res << endl;
}