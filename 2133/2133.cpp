#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> dp(31);
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=30; i+=2) {
        dp[i] = dp[i-2]*3;
        for(int j=0; j<=i-4; j+=2) {
            dp[i] += dp[j]*2;
        }
    }
    cout << dp[n] << endl;
}