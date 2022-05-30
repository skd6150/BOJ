#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct digit {
    char alphabet;
    long long int score;
};

bool cmp(digit a, digit b) {
    return a.score > b.score;
}

int main() {
    int n;
    long long int res = 0;
    cin >> n;
    vector<digit> scores;
    vector<int> translate(10);
    vector<string> words;
    vector<bool> check(n, false);
    for(int i=0; i<10; i++) scores.push_back({(char)('A'+i), 0});
    for(int i=0; i<n; i++) {
        string tmp;
        long long int score = 1;
        cin >> tmp;
        words.push_back(tmp);
        for(int j=tmp.size()-1; j>=0; j--) {
            scores[tmp[j]-'A'].score += score;
            score *= 10;
        }
        check[tmp[0]-'A'] = true;
    }
    sort(scores.begin(), scores.end(), cmp);

    if(check[scores[9].alphabet - 'A']) {
        int idx;
        for(int i=8; i>=0; i--) {
            if(!check[scores[i].alphabet - 'A']) {
                idx = i;
                break;
            }
        }
        for(int i=idx; i<9; i++) {
            swap(scores[i], scores[i+1]);
        }
    }

    for(int i=0; i<10; i++) {
        translate[scores[i].alphabet-'A'] = 9-i;
    }

    for(string word: words) {
        long long int power = 1;
        for(int i=word.size()-1; i>=0; i--) {
            res += translate[word[i] - 'A'] * power;
            power *= 10;
        }
    }
    cout << res << endl;
}