#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long int m, n, invest[22][330], dp[22][330];
    vector<int> records[22][330];
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        int money;
        cin >> money;
        for(int j=0; j<n; j++) {
            int profit;
            cin >> profit;
            invest[j][money] = profit;
        }
    }

    for(int i=0; i<=m; i++) {
        dp[0][i] = invest[0][i];
        records[0][i].push_back(i);
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=m; j++) {
            long long int maxProfit = -9876543210;
            int record;
            for(int k=0; k<=j; k++) {
                int newProfit = dp[i-1][j-k] + invest[i][k];
                if(maxProfit < newProfit) {
                    maxProfit = newProfit;
                    record = k;
                }
            }
            dp[i][j] = maxProfit;
            records[i][j].assign(records[i-1][j-record].begin(), records[i-1][j-record].end());
            records[i][j].push_back(record);

        }
    }

    cout << dp[n-1][m] << endl;
    for(int p: records[n-1][m]) {
        cout << p << " ";
    }
    cout << endl;
}