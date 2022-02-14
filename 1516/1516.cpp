#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, checked = 0;
    cin >> n;
    vector<int> ranks(n);
    vector<int> costs;
    vector<vector<int>> adj(n);
    vector<int> result(n);
    for(int i=0; i<n; i++) {
        int time;
        cin >> time;
        while(true) {
            int tmp;
            cin >> tmp;
            if(tmp == -1) break;
            adj[tmp-1].push_back(i);
            ranks[i]++;
        }
        costs.push_back(time);
    }

    // for(int i=0; i<n; i++) {
    //     cout << i << ": ";
    //     for(int j=0; j<adj[i].size(); j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(checked != n) {
        int cur, cost;
        for(int i=0; i<n; i++) {
            if(ranks[i] == 0) {
                cur = i;
                cost = costs[i];
                ranks[i] = -1;
                checked++;
                break;
            }
        }
        result[cur] = result[cur] + cost;
        for(int next: adj[cur]) {
            result[next] = max(result[next], result[cur]);
            ranks[next]--;
        }
    }
    
    for(int i: result) {
        cout << i << endl;
    }
}