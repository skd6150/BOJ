#include <iostream>
#include <vector>
#define R 100000
using namespace std; 

bool flag[100100];
vector<int> V[2]; 

int main() {
	int N, K, t=0;
	cin >> N >> K;

	if(N==0) V[0].push_back(N);
	else for(int i=N; i<=R; i*=2) {
		flag[i] = true;
		V[0].push_back(i);
	}

	while(true) {
		vector<int> store;
		if(flag[K]) {
			cout << t << endl;
		break;
		}
		for(int cur: V[t%2]) {
			if(cur+1<=R && !flag[cur+1]) {
				flag[cur+1] = true;
				V[(t+1)%2].push_back(cur+1);
				store.push_back(cur+1);
			}
			if(cur-1 >= 0 && !flag[cur-1]) {
				flag[cur-1] = true;
				V[(t+1)%2].push_back(cur-1);
				store.push_back(cur-1);
			}
		}
		for(int cur: store) {
			if(cur == 0) continue;
			for(int i=cur*2; i<=R; i*=2) {
				if(flag[i]) break;
				flag[i] = true;
				V[(t+1)%2].push_back(i);
			}
		}
		vector<int>().swap(V[t%2]);
		vector<int>().swap(store);
		t++;
	}
}