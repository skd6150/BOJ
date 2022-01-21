#include <iostream>
#include <vector>
using namespace std;

int req, pizzaSize[2], memo[2][2000000], res=0;

int main() {
    cin >> req >> pizzaSize[0] >> pizzaSize[1];
    for(int i=0; i<2; i++) {
        vector<int> pizza, sum(pizzaSize[i]*2, 0);
        for(int j=0; j<pizzaSize[i]; j++) {
            int tmp;
            cin >> tmp;
            pizza.push_back(tmp);
        }
        sum[0] = pizza[0];
        for(int j=1; j<pizzaSize[i]*2; j++) {
            sum[j] = sum[j-1] + pizza[j % pizzaSize[i]];
        }
        for(int start=0; start<pizzaSize[i]; start++) {
            for(int width=1; width<pizzaSize[i]; width++) {
                int pizzaSize = sum[start+width] - sum[start];
                memo[i][pizzaSize]++;
            }
        }
        memo[i][sum[pizzaSize[i]-1]] = 1;
    }

    for(int i=0; i<2; i++) {
        res += memo[i][req];
    }
    for(int i=1; i<=req; i++) {
        int j=req-i;
        res += memo[0][i] * memo[1][j];
    }
    cout << res << endl;
}