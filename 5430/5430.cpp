#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string cmd, input;
        deque<int> arr;
        bool err = false, direction = false;
        int size;
        cin >> cmd >> size >> input;
        for(int i=1; i < input.size();) {
            int idx=i;
            string number = "";
            while(input[idx] != ',' && input[idx] != ']') {
                number += input[idx++];
            }
            i=idx+1;
            if(!number.empty()) arr.push_back(stoi(number));
        }

        for(char p: cmd) {
            if(p == 'R') {
                direction = !direction;
            }
            else if(p == 'D') {
                if(arr.size() == 0) {
                    err = true;
                    break;
                }
                if(direction) {
                    arr.pop_back();
                }
                else {
                    arr.pop_front();
                }
            }
        }
        if(err) cout << "error" << endl;
        else {
            cout << '[';
            if(direction) {
                for(int i=arr.size()-1; i>=0; i--) {
                    cout << arr[i];
                    if(i!=0) cout << ',';
                }
            }
            else {
                for(int i=0; i<arr.size(); i++) {
                    cout << arr[i];
                    if(i!=arr.size()-1) cout << ',';
                }
            }
            cout << ']' << endl;
        }
    }
}