#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> dp[15][15]; //dp[m][n]: n으로 시작하는 m자리 감소하는 수

int main() {
    int n;
    cin >> n;

    for(int i=0; i<10; i++) {
        dp[1][i].push_back(to_string(i));
        if(!n--) {
            cout << to_string(i) << endl;
            return 0;
        }
    }

    for(int i=2; i<=10; i++) {
        for(int j=i-1; j<10; j++) {
            for(int k=0; k<j; k++) {
                for(string str: dp[i-1][k]) {
                    dp[i][j].push_back(to_string(j) + str);
                    if(!n--) {
                        cout << to_string(j) + str << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}