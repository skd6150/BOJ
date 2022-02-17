#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int target, int start, int end, vector<int>& arr) {
    if(start == end) {
        if(arr[start] == target) return start;
        else return -1;
    };
    int mid = (start + end)/2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return find(target, start, mid, arr);
    else return find(target, mid+1, end, arr);
}

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    vector<bool> check(n, false);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int idx = find(arr[i] + arr[j], 0, n-1, arr);
            if(idx == -1) continue;
            if(check[idx]) continue;
            int start, end;
            for(int k=idx; arr[k] == arr[idx] && k >= 0; k--) start = k;
            for(int k=idx; arr[k] == arr[idx] && k < n; k++) end = k;
            if(end - start <= 2 && (idx == i || idx == j)) continue;
            cout << i << " " << j << " " << start << " " << end << " " << idx << endl;
            for(int k=start; k<=end; k++) check[k] = true;
        }
    }
    for(int i=0; i<n; i++) {
        if(check[i]) {
            res++;
            // cout << arr[i] << endl;
        }
    }
    cout << res << endl;
}