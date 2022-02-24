#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

struct pivot {
    int n;
    int p;
    int count;
};

int main() {
    int n;
    cin >> n;
    int res = MAX;
    vector<vector<vector<pair<int, int>>>> edges(n+1);
    vector<vector<bool>> check(n+1);;
    for(int i=0; i<=n; i++) {
        edges[i].resize(n+1);
        check[i].resize(n+1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            edges[i][j].push_back(make_pair(i,i));
        }
        for(int j=0; j<=n; j++) {
            if(i==1) continue;
            edges[i][j].push_back(make_pair(i-1, j));
        }
        for(int j=1; i+j<=n; j++) {
            edges[i][j].push_back(make_pair(i+j, j));
        }
    }

    queue<pivot> Q;
    Q.push({1,0,0});
    check[1][0] = true;
    while(!Q.empty()) {
        pair<int, int> pos = make_pair(Q.front().n, Q.front().p);
        int count = Q.front().count;
        Q.pop();
        if(pos.first == n) res = min(res, count);
        for(pair<int, int> next: edges[pos.first][pos.second]) {
            if(check[next.first][next.second]) continue;
            Q.push({next.first, next.second, count+1});
            check[next.first][next.second] = true;
        }
    }
    cout << res << endl;
}