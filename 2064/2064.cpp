#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> itob(int dec) {
    vector<bool> arr;
    int mod = 128;
    while(mod != 0) {
        if(dec >= mod) {
            arr.push_back(true);
            dec -= mod;
        }
        else arr.push_back(false);
        mod /= 2;
    }
    return arr;
}

void print(vector<bool> address) {
    for(int i=0; i<4; i++) {
        int sum = 0;
        int num = 128;
        for(int j=0; j<8; j++) {
            if(address[i*8 + j]) sum += num;
            num /= 2;
        }
        cout << sum;
        if(i != 3) cout << ".";
        else cout << endl;
    }
}

int main() {
    int n, mask = 32;
    cin >> n;
    vector<vector<bool>> addresses(n);
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        tmp = tmp + ".";
        int idx = 0;
        for(int j=0; j<tmp.size(); j++) {
            if(tmp[j] != '.') continue;
            string substr = tmp.substr(idx, j);
            idx = j+1;
            vector<bool> bin = itob(stoi(substr.c_str()));
            for(bool bit: bin) addresses[i].push_back(bit);
        }
    }

    for(int i=0; i<32; i++) {
        bool bit = addresses[0][i];
        bool flag = true;
        for(int j=1; j<addresses.size(); j++) {
            if(addresses[j][i] != bit) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            mask = i;
            break;
        }
    }

    vector<bool> subnetmask(32, true);
    for(int i=mask; i<32; i++) {
        addresses[0][i] = 0;
        subnetmask[i] = 0;
    }

    print(addresses[0]);
    print(subnetmask);
}