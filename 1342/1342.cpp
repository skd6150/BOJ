#include <iostream>
#include <string>
using namespace std;

int alphabet[26];
int ft[15];

bool isLucky(string str) {
	int size = str.size();
	for(int i=1; i<size; i++) {
		if(str[i] == str[i-1]) return false;
	}
	return true;
}

int findLucky(string matched, string unmatched, int num) {
	// cout << matched << " " << unmatched << endl;
	int new_num = num;
	int unmatchedSize = unmatched.size();
	if(unmatchedSize == 0) {
		if(isLucky(matched)) {
			return 1;
		}
		else return 0;
	}
	for(int i=0; i<unmatchedSize; i++) {
		string new_matched = matched + unmatched[i];
		string new_unmatched = unmatched.substr(0,i) + unmatched.substr(i+1);
		new_num += findLucky(new_matched, new_unmatched, num);
	}
	return new_num;
}

int main() {
	int ret, devide = 1;
	string input;
	cin >> input;
	
	for(int i=0; i<input.size(); i++) {
		alphabet[(int)input[i] - (int)'a']++;
	}
	
	ft[0] = 1; ft[1] = 1;
	for(int i=2; i<=input.size(); i++) {
		ft[i] = ft[i-1]*i;
	}
	
	for(int i=0; i<26; i++) {
		devide *= ft[alphabet[i]];
	}
	
	ret = findLucky("", input, 0);
	cout << ret/devide << endl;
}