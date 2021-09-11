#include <bits/stdc++.h>
using namespace std;

string arr[1010];
int K, N;
string padding = "0";
bool paddingFlag = false;

bool cmp(string a, string b) {
	return a+b > b+a;
}

// bool cmp(string a, string b) {
// 	string ab = a.append(b);
// 	string ba = b.append(a);
// 	for(int i=0; i<ab.size(); i++) {
// 		if(ab[i] == ba[i]) continue;
// 		if(ab[i] > ba[i]) return true;
// 		else return false;
// 	}
// 	return true;
// } -> sort함수와 사용시 메모리초과!

bool cmpLonger(string a, string b) {
	if(a.size() == b.size()) {
		return cmp(a, b);
	}
	if(a.size() > b.size()) return true;
	else return false;
}

int main() {
	cin >> K >> N;
	for(int i=0; i<K; i++) {
		cin >> arr[i];
		if(cmpLonger(arr[i], padding)) padding = arr[i];
	}
	
	//sort(arr, arr+K, cmp); -> 메모리초과!
	stable_sort(arr, arr+K, cmp);
	for(int i=0; i<K; i++) {
		cout << arr[i];
		if(!paddingFlag && (i == K-1 || cmp(padding, arr[i+1]))) {
			paddingFlag = true;
			for(int j=0; j<N-K; j++) {
				cout << padding;
			}
		}
	}
	cout << endl;
}