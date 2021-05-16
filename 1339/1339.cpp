#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct obj {
	int score;
	char ch;
};

bool cmp(obj a, obj b) {
	return (a.score > b.score) ? true : false;
}

int pow(int n, int p) {
	for(int i=0; i<p; i++) n*=10;
	return n;
}

obj importance[26];
int en_to_num[26];

int main() {
	string arr[11];
	int N, res = 0;
	cin >> N;
	for(int i=0; i<26; i++) importance[i].ch = 'A' + i;
	for(int i=0; i<N; i++) cin >> arr[i];
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<arr[i].size(); j++) {
			int idx = arr[i][j] - 'A';
			importance[idx].score += pow(1, arr[i].size()-j);
		}
	}
	sort(importance, importance+26, cmp);
	for(int i=0; i<26; i++) {
		en_to_num[importance[i].ch - 'A'] = 9 - i;
	}
	
	// for(int i=0; i<26; i++) {
	// 	cout << importance[i].score << " ";
	// }
	// cout << endl;
	// for(int i=0; i<26; i++) {
	// 	cout << en_to_num[i] << " ";
	// }
	// cout << endl;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<arr[i].size(); j++) {
			int tmp = en_to_num[arr[i][j] - 'A'];
			res += pow(tmp, arr[i].size() - j - 1);
		}
	}
	cout << res << endl;
}