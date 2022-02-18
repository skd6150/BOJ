#include <iostream>
#include <vector>
using namespace std;

int find(int idx, vector<int>& arr) {
    if(arr[idx] == idx) return idx;
    else return arr[idx] = find(arr[idx], arr);
}

void merge(int idxA, int idxB, vector<int>& arr) {
    int treeA = find(idxA, arr);
    int treeB = find(idxB, arr);
    if(treeA == treeB) return;
    else {
        arr[treeA] = treeB;
    }
}

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> arr, timetable(n);
    for(int i=0; i<n; i++) arr.push_back(i);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b, arr);
    }
    for(int i=0; i<n; i++) {
        cin >> timetable[i];
    }
    for(int i=0; i<n-1; i++) {
        if(find(timetable[i], arr) == find(timetable[i+1], arr)) continue;
        res++;
    }
    cout << res << endl;
}