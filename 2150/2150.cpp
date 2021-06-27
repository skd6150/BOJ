#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int numVertex, numEdge; //정점, 간선 개수
vector<vector<int>> adj, sccContainer; // 인접리스트, 각 SCC끼리 묶을 벡터
vector<int> sccId, discovered; // 각 정점에 SCC ID를 매칭할 벡터, dfs상 탐색된 순서
stack<int> S;
int sccCounter=0, vertexCounter=0; // sccID저장, 정점 발견 순서 저장

int min(int a, int b) {
	return a > b ? b : a;
}
bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0] ? true : false;
}

int scc(int cur) {
	int ret = discovered[cur] = vertexCounter++; // 현재 정점이 탐색된 순서
	S.push(cur); // 스택 안쪽에 있을수록 dfs스패닝트리 상 부모노드
	for(int i=0; i<adj[cur].size(); i++) {
		int next = adj[cur][i];
		if(discovered[next] == -1) {
			ret = min(ret, scc(next)); //DFS 겸 ret를 SCC상 가장 빨리 발견된 정점의 discovered로 최신화
		}
		else if(sccId[next] == -1) { // next가 아직 SCC에 포함되지 않은경우, 즉 cur과 next가 교차간선으로 이어져있으며 한 SCC에 포함될때
			ret = min(ret, discovered[next]);
		}
	}
	if(ret == discovered[cur]) { // cur가 SCC상에서 가장 높은 정점이고 부모노드는 SCC에 포함되지 않을때
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

void tarjanScc() {
	sccId = discovered = vector<int>(numVertex, -1);
	for(int i=0; i<numVertex; i++) if(discovered[i] == -1) scc(i);
}

int main() {
	scanf("%d %d", &numVertex, &numEdge);
	adj.resize(numVertex+1);
	for(int i=0; i<numEdge; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from-1].push_back(to-1);
	}
	tarjanScc();
	sccContainer.resize(sccCounter);
	for(int i=0; i<numVertex; i++) {
		sccContainer[sccId[i]].push_back(i+1);
	}
	
	printf("%d\n", sccCounter);
	for(int i=0; i<sccCounter; i++) {
		sort(sccContainer[i].begin(), sccContainer[i].end());
	}
	sort(sccContainer.begin(), sccContainer.end(), cmp);
	for(int i=0; i<sccCounter; i++) {
		for(int j=0; j<sccContainer[i].size(); j++) {
			printf("%d ", sccContainer[i][j]);
		}
		printf("-1\n");
	}
}