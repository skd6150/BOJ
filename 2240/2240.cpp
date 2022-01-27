#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, w, result = -1;;
    cin >> t >> w;
    vector<vector<int>> dp(t);
    vector<int> score(t);
    for(int i=0; i<t; i++) {
        dp[i].resize(w+1);
    }
    for(int i=0; i<t; i++) {
        cin >> score[i];
    }
    dp[0][score[0] == 2] = 1;

    for(int i=1; i<t; i++) {
        if(score[i] == 1) dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = dp[i-1][0];
        for(int j=1; j<=min(w, i+1); j++) {
            int pos = j%2 + 1;
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (score[i] == pos);
        }
    }

    for(int value: dp[t-1]) {
        result = max(result, value);
    }
    cout << result << endl;
}