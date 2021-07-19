#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
int variableNum, clauseNum, sccCounter=0, vertexCounter=0;
vector<int> sccId, discovered, value;
stack<int> S;

int min(int a, int b) {
	return a > b ? b : a;
}
int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	S.push(here);
	for(int i=0; i<adj[here].size(); i++) {
		int there = adj[here][i];
		if(discovered[there] == -1) {
			ret = min(ret, scc(there));
		}
		else if(sccId[there] == -1) {
			ret = min(ret, discovered[there]);
		}
	}
	if(ret == discovered[here]) {
		while(true) {
			int top = S.top();
			S.pop();
			sccId[top] = sccCounter;
			if(top == here) break;
		}
		sccCounter++;
	}
	return ret;
}
vector<int> targanSCC() {
	sccId = discovered = vector<int>(variableNum*2, -1);
	for(int i=0; i<variableNum*2; i++) {
		if(discovered[i] == -1) scc(i);
	}
	return sccId;
}

int main() {
	scanf("%d %d", &variableNum, &clauseNum);
	adj.resize(variableNum*2);
	value = vector<int>(variableNum, -1);
	for(int i=0; i<clauseNum; i++) {
		int v[2];
		int vIdx[2];
		scanf("%d %d", &v[0], &v[1]);
		for(int i=0; i<2; i++) {
			if(v[i] > 0) vIdx[i] = (v[i]-1)*2;
			else vIdx[i] = ((v[i]*-1)-1)*2+1;
		}
		for(int i=0; i<2; i++) {
			if(vIdx[i]%2 == 0) adj[vIdx[i]+1].push_back(vIdx[!i]);
			else adj[vIdx[i]-1].push_back(vIdx[!i]);
		}
	}
	vector<int> sccIdx = targanSCC();
	vector<pair<int, int>> sccLabel;
	for(int i=0; i<variableNum*2; i+=2) {
		if(sccIdx[i] == sccIdx[i+1]) {
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i=0; i<variableNum*2; i++) {
		sccLabel.push_back(make_pair(-1*sccIdx[i], i));
	}
	sort(sccLabel.begin(), sccLabel.end());
	for(int i=0; i<variableNum*2; i++) {
		int variable = sccLabel[i].second/2;
		bool isTrue = (sccLabel[i].second%2) == 0;
		if(value[variable] != -1) continue;
		value[variable] = !isTrue;
	}
	printf("1\n");
	for(int i=0; i<variableNum; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}