#include <iostream>
#include <vector>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    int length = a.size();
    for(int i=0; i<length; i++) {
        if(a[i] == b[i]) continue;
        return false;
    }
    return true;
}

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> goal(n), dest(n), cur(n), init(n);
    for(int i=0; i<n; i++) {
        goal[i] = i % 3;
    }
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> cur[i];
    }
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> dest[i];
    }
    init = cur;
    
    while(!compare(cur, goal)) {
        if(res > 0 && cur == init) {
            res = -1;
            break;
        }
        res++;
        vector<int> next(n);
        for(int i=0; i<n; i++) {
            next[dest[i]] = cur[i];
        }
        cur = next;
    }
    cout << res << endl;
}