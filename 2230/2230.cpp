#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long int n, m, result = 9876543210;
    int left = 0, right = 1;
    vector<long long int> arr;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), less<long long int>());
    
    while(true) {
        // cout << arr[left] << " " <<  arr[right] << endl;
        long long int diff = arr[right] - arr[left];
        if(right == arr.size()-1 && diff < m) break;
        if(diff >= m) {
            result = min(result, diff);
        }
        if(diff == m) break;
        if(diff < m) {
            right++;
        }
        else left++;
    }

    cout << result << endl;
}