#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, res = -1;
    scanf("%d", &n);
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++) {
        res = max(res, abs(arr[i] - 2 * arr[i+1] + arr[n-1]));
    }
    for(int i=n-1; i>=2; i--) {
        res = max(res, abs(arr[0] - 2 * arr[i-1] + arr[i]));
    }
    printf("%d\n", res);
}