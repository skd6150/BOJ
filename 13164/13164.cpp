#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    long long int res = 0;
    vector<int> input;
    priority_queue<int> pq;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    for(int i=1; i<n; i++) {
        res += input[i] - input[i-1];
        pq.push(input[i] - input[i-1]);
    }
    for(int i=0; i<k-1; i++) {
        res -= pq.top();
        pq.pop();
    }
    cout << res << endl;
}