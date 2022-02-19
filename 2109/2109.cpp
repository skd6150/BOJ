#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, res = 0, day = 0;
    scanf("%d", &n);
    priority_queue<pair<int, int>> arr;
    priority_queue<int> available;
    for(int i=0; i<n; i++) {
        int d, p;
        scanf("%d %d", &p, &d);
        day = max(day, d);
        arr.push(make_pair(d, p));
    }
    while(day != 0) {
        while(!arr.empty() && arr.top().first >= day) {
            available.push(arr.top().second);
            arr.pop();
        }
        if(!available.empty()) {
            res += available.top();
            available.pop();
        }
        day--;
    }
    printf("%d", res);
}