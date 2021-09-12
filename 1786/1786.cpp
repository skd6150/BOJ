#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;

vector<int> getPi(string pattern) {
	int len = pattern.size();
	vector<int> pi(len, 0);
	int begin=1, matched=0;
	while(begin+matched < len) {
		if(pattern[begin+matched] == pattern[matched]) {
			matched++;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched==0) begin++;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> findWord(string text, string pattern) {
	int lenText = text.size();
	int lenPattern = pattern.size();
	int begin=0, matched=0;
	vector<int> pi = getPi(pattern);
	vector<int> res(1, 0);
	while(begin < lenText) {
		if(matched < lenPattern && text[begin+matched] == pattern[matched]) {
			matched++;
			if(matched == lenPattern) {
				res.push_back(begin+1);
				res[0]++;
			}
		}
		else {
			if(matched == 0) begin++;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return res;
}

int main() {	
	char text[N], pattern[N];
	scanf("%[^\n]", text);
	getchar();
	scanf("%[^\n]", pattern);

	// getline(cin, text, '\n');
	// getline(cin, pattern, '\n');
	vector<int> res = findWord(string(text), string(pattern));
	for(int i=0; i<res.size(); i++) cout << res[i] << "\n";
}