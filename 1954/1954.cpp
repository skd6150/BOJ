#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, start = 987654321, end = 0, res = -1;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cin >> m;
    for(int i=0; i<n; i++) {
        start = min(start, arr[i].first + arr[i].second);
        end = max(end, arr[i].first*m+arr[i].second);
    }
    for(int gas=start; gas<=end; gas++) {
        bool flag = true;
        int sum = 0;
        for(pair<int, int> coef: arr) {
            if((gas-coef.second)%coef.first) {
                flag = false;
                break;
            }
            sum += (gas-coef.second) / coef.first;
            if(sum > m) break;
        }
        if(flag && sum == m) {
            res = gas;
            break;
        }
    }
    if(res == -1) cout << 0 << endl;
    else cout << res << endl;
}