#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

vector<string> words;
string str;
int numWords, dp[55];

int min(int a, int b) {
	return a > b ? b : a;
}

int getCost(string cmp, int idx) {
	if(idx+cmp.size() > str.size()) return -1;
	int count[2][26], cost = 0;
	memset(count, 0, sizeof(count));
	for(int i=0; i<cmp.size(); i++) {
		count[0][cmp[i]-'a']++;
		count[1][str[idx+i]-'a']++;
	}
	for(int i=0; i<26; i++) {
		if(count[0][i] != count[1][i]) return -1;
	}
	for(int i=0; i<cmp.size(); i++) {
		if(cmp[i] != str[idx+i]) cost++;
	}
	return cost;
}

int main() {
	cin >> str >> numWords;
	for(int i=1; i<55; i++) dp[i] = 987654321;
	for(int i=0; i<numWords; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}
	
	for(int i=1; i<=str.size(); i++) {
		for(string word: words) {
			int idx = i - word.size();
			if(idx < 0) continue;
			int cost = getCost(word, idx);
			if(cost == -1) continue;
			dp[i] = min(dp[i], dp[idx]+cost);
		}
	}
	
	cout << ((dp[str.size()] > 1000) ? -1 : dp[str.size()]) << endl;
}