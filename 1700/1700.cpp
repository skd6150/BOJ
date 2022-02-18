#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, len, res = 0;
    cin >> n >> len;
    vector<int> arr(len), cur;
    for(int i=0; i<len; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<len; i++) {
        bool flag = false;
        for(int j=0; j<i; j++) {
            if(cur[j] == arr[i]) flag = true;
        }
        if(flag) continue;
        cur.push_back(arr[i]);
        if(cur.size() == n) break;
    }

    for(int i=n; i<len; i++) {
        bool flag = false;
        for(int c: cur) {
            if(c == arr[i]) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        
        res++;
        priority_queue<pair<int, int>> dist;
        for(int j=0; j<n; j++) {
            int score = 0;
            for(int k=i; k<len; k++) {
                if(arr[k] == cur[j]) break;
                else score++;
            }
            dist.push(make_pair(score, j));
        }
        cur[dist.top().second] = arr[i];
    }
    
    cout << res << endl;
}