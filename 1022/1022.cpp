#include <iostream>
#include <iomanip>
using namespace std;

int field[100][100];
int maximum = -1, maxDigit;
pair<int, int> a, b;

int max(int a, int b) {
    return a > b ? a : b;
}

int digit(int num) {
    int result = 0;
    int pivot = 1;
    while(pivot <= num) {
        pivot *= 10;
        result++;
    }
    return result;
}

bool checkBoundary(pair<int, int> pos) {
    if(pos.first >= a.first && pos.first <= b.first && pos.second >= a.second && pos.second <= b.second) return true;
    return false;
}

int fill(int num, int start) {
    if(num == 0) {
        if(checkBoundary(make_pair(0, 0))) {
            field[-a.first][-a.second] = start;
        }
        return 2;
    }

    pair<int, int> pos = make_pair(num-1, num);
    while(pos.first > -num) {
        if(checkBoundary(pos)) {
            field[pos.first - a.first][pos.second - a.second] = start;
            // cout << start << endl;
        }
        start++;
        pos.first--;
    }
    while(pos.second > -num) {
        if(checkBoundary(pos)) {
            field[pos.first - a.first][pos.second - a.second] = start;
            // cout << start << endl;
        }
        start++;
        pos.second--;
    }
    while(pos.first < num) {
        if(checkBoundary(pos)) {
            field[pos.first - a.first][pos.second - a.second] = start;
            // cout << start << endl;
        }
        start++;
        pos.first++;
    }
    while(pos.second <= num) {
        if(checkBoundary(pos)) {
            field[pos.first - a.first][pos.second - a.second] = start;
            // cout << start << endl;
        }
        start++;
        pos.second++;
    }

    return start;
}

int main() {
    cin >> a.first >> a.second >> b.first >> b.second;

    int start = 1;
    for(int i=0; i<=5000; i++) {
        start = fill(i, start);
    }
    for(int i=0; i<=b.first-a.first; i++) {
        for(int j=0; j<=b.second-a.second; j++) {
            maximum = max(maximum, field[i][j]);
        }
    }
    maxDigit = digit(maximum);
    for(int i=0; i<=b.first-a.first; i++) {
        for(int j=0; j<=b.second-a.second; j++) {
            for(int k=digit(field[i][j]); k<maxDigit; k++) cout << " ";
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}