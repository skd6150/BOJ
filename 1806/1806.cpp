#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;

int main() {
    long long int n, s;
    int left = 0, right = 1, result = INF;
    cin >> n >> s;
    vector<long long int> arr(1);
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(arr.back()+tmp);
    }

    while(true) {
        int sum = arr[right] - arr[left];
        if(right == arr.size()-1 && (sum < s || left == arr.size()-1)) {
            break;
        }
        if(sum >= s) {
            result = min(result, right - left);
            left++;
        }
        else {
            right++;
        }
    }
    if(result == INF) cout << 0 << endl;
    else cout << result << endl;
}

