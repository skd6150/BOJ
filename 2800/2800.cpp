#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void getSubset(int idx, int end, int count, vector<bool> cur, vector<vector<bool>>& store) {
    if(idx == end) {
        if(count != end) store.push_back(cur);
        return;
    }
    cur.push_back(false);
    getSubset(idx+1, end, count, cur, store);
    cur.pop_back();
    cur.push_back(true);
    getSubset(idx+1, end, count+1, cur, store);
}

int main() {
    string original;
    stack<int> S;
    vector<pair<int, int>> pos;
    vector<string> res;
    vector<vector<bool>> subset;
    cin >> original;
    for(int i=0; i<original.length(); i++) {
        if(original[i] == '(') S.push(i);
        if(original[i] == ')') {
            pos.push_back(make_pair(S.top(), i));
            S.pop();
        }
    }
    sort(pos.begin(), pos.end());
    getSubset(0, pos.size(), 0, vector<bool>(), subset);
    for(int j=subset.size()-1; j>=0; j--) {
        string tmp = original;
        string str = "";
        for(int i=0; i<subset[j].size(); i++) {
            if(subset[j][i]) continue;
            tmp[pos[i].first] = '_';
            tmp[pos[i].second] = '_';
        }
        for(int i=0; i<tmp.length(); i++) {
            if(tmp[i] == '_') continue;
            str += tmp[i];
        }
        res.push_back(str);
    }
    sort(res.begin(), res.end());
    cout << res[0] << endl;
    for(int i=1; i<res.size(); i++) {
        if(res[i] == res[i-1]) continue;
        cout << res[i] << endl;
    }
}