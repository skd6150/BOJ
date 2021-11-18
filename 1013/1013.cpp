#include <iostream>
#include <string>
using namespace std;

int v[9][2] = {
    {1, 3},
    {-1, 2},
    {1, 3},
    {4, -1},
    {5, -1},
    {5, 6},
    {1, 8},
    {5, 2},
    {7, 8}
};

bool solution(string str) {
    int state = 0;
    for(char ch:str) {
        state = v[state][ch-'0'];
        // cout << "state " << state << endl;
        if(state == -1) return false;
    }
    return state == 8 || state == 6 || state == 2;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        cout << (solution(str) ? "YES" : "NO") << endl;
    }
    return 0;
}