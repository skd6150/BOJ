#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<int> v(n+5, -9999);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    if(n < 3) {
        if(v[0] == v[1]) {
            cout << v[0] << endl;
            return 0;
        }
        else {
            cout << 'A' << endl;
            return 0;
        }
    }

    a = v[1] != v[0] ? (v[2] - v[1]) / (v[1] - v[0]) : 0;
    b = v[1] - a * v[0];

    for(int i=1; i<n; i++) {
        if((v[i-1] * a + b) != v[i]) {
            cout << 'B' << endl;
            return 0;
        };
    }

    cout << v[n-1] * a + b << endl;
}