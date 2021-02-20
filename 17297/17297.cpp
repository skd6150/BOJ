#include <iostream>
#include <vector>
#include <string>
using namespace std;

string messi = "Messi Gimossi ";

long long int devide(long long int idx, long long int N, vector<long long int>& pibo) {
	
	if(N == 0 || N ==1) {
		return idx;
	}
	
	// cout << idx << " " << N << " " << pibo[N] << " " << pibo[N-1] << " " << endl;
	
	if(idx > pibo[N-1]) {
		return devide(idx-pibo[N-1]-1, N-2, pibo);
	}
	else {
		return devide(idx, N-1, pibo);
	}
}

int main() {
	long long int N;
	vector<long long int> pibo;
	
	cin >> N;
	N--;
	
	pibo.push_back(5);
	pibo.push_back(13);
	int i = 1;
	while(i++) {
		pibo.push_back(pibo[i-1] + pibo[i-2] + 1);
		if(pibo.back() > N) break;
	}
	
	int ret = devide(N, pibo.size() - 1, pibo);
	char msg = messi[ret];
	
	// cout << ret << " " << msg << endl;
	
	if(msg == ' ') cout << "Messi Messi Gimossi" << endl;
	else cout << msg << endl;
}