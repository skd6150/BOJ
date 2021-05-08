#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes[1001000];
bool visit[1001000];
int numWin = 0;
int numLeaf = 0;

void game(int node, bool win) {
	//cout << "node " << node << endl;
	for(int i=0; i<nodes[node].size(); i++) {
		if(!visit[nodes[node][i]]) {
			visit[nodes[node][i]] = true;
			game(nodes[node][i], !win);
		}
	}
	if(nodes[node].size() == 1) {
		numLeaf++;
		if(win) {
			numWin++;
		}
		return;
	}
}

int main() {
	int N, start, err = 0;
	scanf("%d", &N);
	for(int i=0; i<N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	for(int i=1; i<=N; i++) {
		if(N != 1 && nodes[i].size() == N-1) err = -1;
	}
	for(int i=1; i<=N; i++) {
		if(nodes[i].size() == 1) {
			start = i;
			break;
		}
	}
	//cout << "start " << start << endl;
	visit[start] = true;
	if(N > 1) game(start, true);
	if(N == 1) printf("1\n");
	else printf("%d\n", ((numWin > numLeaf-numWin) ? numWin : numLeaf-numWin)+err);
}