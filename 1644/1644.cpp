#include <iostream>
#include <vector>
#include <memory.h>
#define N 4004000
using namespace std;

vector<int> decimal;

bool check[N];

int main() {
    int target, res = 0;
    cin >> target;

    for(int i=2; i<N; i++) {
        if(check[i]) continue;
        decimal.push_back(i);
        for(int j=i; j<N; j+=i) {
            check[j] = true;
        }
    }

    int start = 0, end = 0, sum = 0;;
    while(end < decimal.size()) {
        if(sum >= target) {
           sum -= decimal[start++]; 
        }
        else if (end == decimal.size()) {
            break;
        }
        else {
            sum += decimal[end++];
        }
        if(sum == target) res++;
    }
    cout << res << endl;
}