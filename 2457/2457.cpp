#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

int dtoi(pair<int, int> d) {
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    int res = d.second - 1;
    for(int i=1; i<d.first; i++) {
        res += days[i-1];
    }
    return res;
}

int main() {
    int n, res = 0, cur = dtoi(make_pair(3, 1));
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> flowers;
    for(int i=0; i<n; i++) {
        pair<int, int> p, q;
        cin >> p.first >> p.second >> q.first >> q.second;
        flowers.push(make_pair(dtoi(p), dtoi(q)));
    }
    while(!flowers.empty()) {
        if(cur > dtoi(make_pair(11, 30))) break;
        if(flowers.top().first > cur) break;
        int maxDate = cur;
        while(!flowers.empty() && flowers.top().first <= cur) {
            maxDate = max(maxDate, flowers.top().second);
            // cout << flowers.top().first << "  " << flowers.top().second << endl;
            flowers.pop();
        }
        cur = maxDate;
        // cout << cur << endl;
        res++;
    }
    if(cur > dtoi(make_pair(11, 30))) cout << res << endl;
    else cout << 0 << endl;
}