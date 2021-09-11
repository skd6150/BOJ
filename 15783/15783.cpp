#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int numVertex, numEdge;
int sccCounter = 0, vertexCounter = 0, minVirus = 0;
vector<int> sccId, discovered;
vector<vector<int>> adj, sccContainer;
vector<bool> infected;
stack<int> S;

int min(int a, int b) {
	return a > b ? b : a;
}
int scc(int cur) {
	int ret = discovered[cur] = vertexCounter++;
	S.push(cur);
	for(int i=0; i<adj[cur].size(); i++) {
		int next = adj[cur][i];
		if(discovered[next] == -1) {
			ret = min(ret, scc(next));
		}
		else if(sccId[next] == -1) {
			ret = min(ret, discovered[next]);
		}
	}
	if(ret == discovered[cur]) {
		while(true) {
			int top = S.top();
			S.pop();
			sccId[top] = sccCounter;
			if(top == cur) break;
		}
		sccCounter++;
	}
	return ret;
}
void targanScc() {
	sccId = discovered = vector<int>(numVertex, -1);
	for(int i=0; i<numVertex; i++) if(discovered[i] == -1) scc(i);
}
void virus(int sccid) {
	for(int i=0; i<sccContainer[sccid].size(); i++) {
		infected[sccContainer[sccid][i]] = true;
	}
	for(int i=0; i<sccContainer[sccid].size(); i++) {
		int water = sccContainer[sccid][i];
		for(int j=0; j<adj[water].size(); j++) {
			int next = adj[water][j];
			if(!infected[next]) virus(sccId[next]);
		}
	}
}

int main() {
	cin >> numVertex >> numEdge;
	adj.resize(numVertex);
	infected.resize(numVertex, false);
	for(int i=0; i<numEdge; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	targanScc();
	sccContainer.resize(sccCounter);
	for(int i=0; i<numVertex; i++) {
		sccContainer[sccId[i]].push_back(i);
	}
	for(int i=sccCounter-1; i>=0; i--) {
		if(!infected[sccContainer[i][0]]) {
			minVirus++;
			virus(i);
		}
	}
	cout << minVirus << endl;
}