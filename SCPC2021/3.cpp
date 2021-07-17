#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int vNum, deNum, udeNum;
bool res[550];
bool check[550];

bool isCycle(vector<int> adj[550], int root) {
	bool findFlag = false;
	memset(check, 0, sizeof(check));
	stack<int> S;
	S.push(root);
	check[root] = true;
	while(!S.empty()) {
		int here = S.top();
		S.pop();
		for(int i=0; i<adj[here].size(); i++) {
			if(adj[here][i] == root) {
				findFlag = true;
				break;
			}
			if(!check[adj[here][i]]) {
				check[adj[here][i]] = true;
				S.push(adj[here][i]);
			}
		}
		if(findFlag) break;
	}
	return findFlag;
}

void solve() {
	vector<int> dAdj[550];
	pair<int, int> udAdj[550];
	memset(res, 0, sizeof(res));
	cin >> vNum >> deNum >> udeNum;
	
	for(int i=0; i<deNum; i++) {
		int from, to;
		cin >> from >> to;
		dAdj[from].push_back(to);
	}
	for(int i=0; i<udeNum; i++) {
		cin >> udAdj[i].first >> udAdj[i].second;
	}
	for(int i=0; i<udeNum; i++) {
		bool cycleFlag;
		dAdj[udAdj[i].first].push_back(udAdj[i].second);
		cycleFlag = isCycle(dAdj, udAdj[i].first);
		if(cycleFlag) {
			dAdj[udAdj[i].first].pop_back();
			dAdj[udAdj[i].second].push_back(udAdj[i].first);
			res[i] = true;
		}
	}
	for(int i=0; i<udeNum; i++) cout << res[i];
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		cout << "Case #" << i+1 << endl;
		solve();
	}
}