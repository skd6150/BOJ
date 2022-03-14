#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, res = 0;
        cin >> n;
        vector<int> files(n), psum(n+1);
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            cin >> files[i];
            psum[i+1] += psum[i] + files[i];
        }
        for(int i=2; i<=n; i++) {
            for(int j=0; j<n-i+1; j++) {
                int start = j;
                int end = j+i-1;
                int cost = 987654321;
                int size = psum[end+1] - psum[start];
                for(int k=1; k<i; k++) {
                    cost = min(cost, dp[start][start+k-1] + dp[start+k][end] + size);
                }
                dp[start][end] = cost;
            }
        }
        cout << dp[0][n-1] << endl;
    }
}