#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int h, w, res = 0;
    cin >> h >> w;
    vector<vector<bool>> field(h, vector<bool>(w));
    vector<vector<int>> dp(h, vector<int>(w));
    for(int i=0; i<h; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<w; j++) {
            field[i][j] = tmp[j] == '1';
            if(field[i][j]) res = 1;
        }
    }
    for(int i=0; i<h; i++) dp[i][0] = field[i][0];
    for(int i=0; i<w; i++) dp[0][i] = field[0][i];
    for(int i=1; i<h; i++) {
        for(int j=1; j<w; j++) {
            if(!field[i][j]) continue;
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            res = max(res, dp[i][j]);
        }
    }
    // for(int i=0; i<h; i++) {
    //     for(int j=0; j<w; j++) {
    //         cout << field[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res*res << endl;
}