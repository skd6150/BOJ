#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int convert(char num) {
    if(num >= '0' && num <= '9') return num - '0';
    else return num - 'A' + 10;
}
char convert(int num) {
    if(num >= 0 && num <= 9) return num + '0';
    else {
        return num - 10 + 'A';
    }
}

string add(string num1, string num2) {
    if(num2.size() > num1.size()) {
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    for(int i=0; i<num2.size(); i++) {
        int idx1 = num1.size()-i-1;
        int idx2 = num2.size()-i-1;
        int addResult = convert(num1[idx1]) + convert(num2[idx2]);
        bool flag = false;
        if(addResult >= 36) {
            flag = true;
            addResult %= 36;
        }
        num1[idx1] = convert(addResult);
        while(flag) {
            idx1--;
            if(idx1 < 0) {
                num1 = "1" + num1;
                flag = false;
            }
            else {
                if(num1[idx1] == 'Z') {
                    num1[idx1] = '0';
                }
                else {
                    num1[idx1] = convert(convert(num1[idx1])+1);
                    flag = false;
                }
            }
        }
    }
    return num1;
};

bool cmp(pair<string, int> a, pair<string, int> b) {
    if(a.first.length() == b.first.length()) {
        for(int i=0; i<a.first.length(); i++) {
            if(a.first[i] != b.first[i]) return convert(a.first[i]) > convert(b.first[i]);
        }
    }
    return a.first.length() > b.first.length();
}

int main() {
    int n, k;
    string sum = "";
    vector<string> numbers;
    vector<pair<string, int>> digits;
    vector<char> zArr;
    cin >> n;

    for(int i=0; i<36; i++) digits.push_back(make_pair("", i));
    for(int i=0; i<n; i++) {
        string tmp;
        string power = "";
        cin >> tmp;
        numbers.push_back(tmp);
        
        for(int j=tmp.size()-1; j>=0; j--) {
            int digit = convert(tmp[j]);
            if(convert('Z') != digit) digits[digit].first = add(convert(convert('Z') - digit) + power, digits[digit].first);
            power += "0";
        }
    }

    cin >> k;
    sort(digits.begin(), digits.end(), cmp);

    for(auto digit: digits) {
        if(zArr.size() >= k) break;
        zArr.push_back(convert(digit.second));
    }

    // for(int i=0; i<36; i++) {
    //     cout << digits[i].first << " " << convert(digits[i].second) << endl;
    // }

    for(int i=0; i<n; i++) {
        for(int j=0; j<numbers[i].size(); j++) {
            char digit = numbers[i][j];
            for(char target: zArr) {
                if(digit == target) numbers[i][j] = 'Z'; 
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        sum = add(sum, numbers[i]);
    }
    
    cout << sum << endl;
}