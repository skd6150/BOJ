#include <iostream>
#include <vector>
#define INF 1000
using namespace std;

int main() {
    int n, res = INF, count=0;
    cin >> n;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<int> score(n+1, 0);
    vector<int> candidate;
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int i=1; i<=n; i++) dist[i][i] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            score[i] = max(score[i], dist[i][j]);
        }
        res = min(res, score[i]);
    }
    for(int i=1; i<=n; i++) {
        if(score[i] == res) {
            candidate.push_back(i);
            count++;
        }
    }
    cout << res << " " << count << endl;
    for(int c: candidate) cout << c << " ";
    cout << endl;
}