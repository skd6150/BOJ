#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
    int v, e, res = INF;
    cin >> v >> e;
    vector<vector<int>> dist(v+1, vector<int>(v+1, INF));
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            for(int k=1; k<=v; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for(int i=1; i<=v; i++) {
        res = min(res, dist[i][i]);
    }
    cout << (res >= INF ? -1 : res) << endl;
}