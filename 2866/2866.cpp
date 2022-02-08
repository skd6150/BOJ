#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool cmp(deque<char> a, deque<char> b) {
    for(int i=0; i<a.size(); i++) {
        if(a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return true;
}

int main() {
    int r, c, res=0;
    cin >> r >> c;
    vector<deque<char>> table(c);
    for(int i=0; i<r; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<c; j++) {
            table[j].push_front(tmp[j]);
        }
    }
    sort(table.begin(), table.end(), cmp);
    for(int i=0; i<c-1; i++) {
        int tmp = 0;
        for(int j=0; j<r; j++) {
            if(table[i][j] == table[i+1][j]) tmp++;
            else break;
        }
        res = max(res, tmp);
    }
    cout << r - res - 1 << endl;
}