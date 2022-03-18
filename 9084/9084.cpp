#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<int> coins(n);
        for(int i=0; i<n; i++) cin >> coins[i];
        cin >> m;
        vector<long long int> dp(m+1);
        dp[0] = 1;
        for(int coin: coins) {
            for(int i=coin; i<=m; i++) {
                dp[i] += dp[i-coin];
            }
        }
        cout << dp[m] << endl;
    }
}