#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// pi함수 구하기
vector<int> getPi(string pattern) {
	int len = pattern.length();
	vector<int> pi(len, 0);
	
	// 자기자신은 찾을 필요가 없으므로 begin 1부터 시작
	int begin=1, matched=0;
	while(begin+matched < len) {
		// pattern[begin+matched] -> 접미사부분
		// pattern[matched] -> 접두사부분
		if(pattern[begin+matched] == pattern[matched]) {
			matched++;
			pi[begin+matched-1] = matched;
		}
		else {
			// 문자열에 접두사==접미사인 부분이 아예 없는경우
			if(matched == 0) begin++;
			// 문자열에 접두사==접미사인 부분이 있는 경우
			else {
				// kmp알고리즘의 원리처럼 다시 처음으로 돌아갈 필요가 없음
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	
	return pi;
}

int findStr(string pattern) {
	string str = pattern + pattern;
	// 문제에서 0<= i < L이라고 주어졌으므로 begin이 0부터 시작
	int begin = 0, matched = 0, res = 0;
	int len = pattern.length();
	vector<int> pi = getPi(pattern);
	while(begin < len) {
		if(matched < len && str[begin+matched] == pattern[matched]) {
			matched++;
			if(matched == len) res++;
		}
		else {
			if(matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return res;
}

string arr[10];

int main() {
	int N, K, res = 0;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	cin >> K;
	
	vector<int> permutation(N);
	for(int i=0; i<N; i++) permutation[i] = i;
	
	do {
		string str = "";
		for(int i=0; i<N; i++) {
			str.append(arr[permutation[i]]);
		}
		if(findStr(str) == K) res++;
	} while(next_permutation(permutation.begin(), permutation.end()));
		
	cout << res << endl;
}