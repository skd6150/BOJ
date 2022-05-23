#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long int n, res = 0;
    cin >> n;
    vector<long long int> arr;
    vector<vector<long long int>> dp(n+1, vector<long long int>(n+1));
    for(int i=0; i<n; i++) {
        long long int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] + arr[i-1] * i;
    for(int i=1; i<=n; i++) dp[0][i] = dp[0][i-1] + arr[n-i] * i;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            long long int coef = i+j;
            dp[i][j] = max(dp[i-1][j] + coef * arr[i-1], dp[i][j-1] + coef * arr[n-j]);
        }
    }
    
    for(int i=0; i<=n; i++) {
        res = max(res, dp[i][n-i]);
    }

    cout << res << endl;
}