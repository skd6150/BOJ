#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, res = 0;
    int idx;
    cin >> n >> m;
    vector<vector<int>> books(2, vector<int>(1, 0));
    for(int i=0; i<n; i++) {
        int pos;
        cin >> pos;
        if(pos > 0) books[0].push_back(pos);
        else books[1].push_back(-pos);
    }
    for(int i=0; i<2; i++) {
        sort(books[i].begin(), books[i].end());
    }

    idx = books[0].back() < books[1].back();
    res += books[idx].back();
    for(int i=0; i<m && books[idx].size() > 0; i++) {
        books[idx].pop_back();
    }

    for(int i=0; i<2; i++) {
        // for(int j=0; j<books[i].size(); j++) cout << books[i][j] << " ";
        // cout << endl;
        while(books[i].size() > 0) {
            res += books[i].back() * 2;
            for(int j=0; j<m && !books[i].empty(); j++) books[i].pop_back();
        }
    }

    cout << res << endl;
}