#include <iostream>
#include <vector>
#include <queue>
#define LL long long int
using namespace std;

int main() {
    int n;
    LL res = 0;
    cin >> n;
    vector<int> count(100100);
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }
    priority_queue<pair<LL, LL>> pq;
    for(int i=0; i<100100; i++) {
        if(count[i] == 0) continue;
        pq.push(make_pair(i, count[i]));
    }
    while(!pq.empty()) {
        queue<pair<LL, LL>> tmp;
        LL length = 1;
        LL qsize = pq.top().first;
        LL cur = qsize;
        if(pq.top().second > 1) tmp.push(make_pair(qsize, pq.top().second-1));
        pq.pop();
        while(!pq.empty() && pq.top().first == cur-1) {
            length++;
            cur = pq.top().first;
            if(pq.top().second > 1) tmp.push(make_pair(cur, pq.top().second-1));
            pq.pop();
        }
        res += qsize * length;
        while(!tmp.empty()) {
            pq.push(tmp.front());
            tmp.pop();
        }
    }
    cout << res << endl;
}