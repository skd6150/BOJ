#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n+1, vector<int>(n+1, INF));
    for(int i=1; i<=n; i++) edges[i][i] = 0;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(edges[a][b] > c) edges[a][b] = c;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(edges[i][j] >= INF) cout << 0 << " ";
            else cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}