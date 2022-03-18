#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string log;
        list<char> password;
        list<char>::iterator idx = password.begin();
        cin >> log;
        for(char c: log) {
            if(c == '<') {
                if(idx != password.begin()) idx--;
            }
            else if(c == '>') {
                if(idx != password.end()) idx++;
            }
            else if(c == '-') {
                if(idx == password.begin()) continue;
                idx = password.erase(--idx);
            }
            else {
                password.insert(idx, c);
            }
        }
        for(char c: password) {
                cout << c;
            }
            cout << endl;
    }
}