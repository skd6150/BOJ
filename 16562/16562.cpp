#include <iostream>
using namespace std;

int parent[10010], minCost[10010], level[10010], popular[10010];
bool visit[10010];

void swap(int& u, int& v) {
	int tmp = u;
	u = v;
	v = tmp;
}

int min(int u, int v) {
	return (u<v)? u:v;
}

int find(int u) {
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return;
	if(level[u] > level[v]) swap(u, v);
	parent[u] = v;
	minCost[v] = min(minCost[u], minCost[v]);
	popular[v] += popular[u];
	if(level[u] == level[v]) level[v]++;
}

int main() {
	int student, link, money, res_cost = 0, res_friend = 0;
	scanf("%d %d %d", &student, &link, &money);
	for(int i=1; i<=student; i++) {
		int cost;
		scanf("%d", &cost);
		parent[i] = i;
		minCost[i] = cost;
		popular[i] = 1;
	}
	for(int i=0; i<link; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for(int i=1; i<=student; i++) {
		int root = find(i);
		if(visit[root]) continue;
		visit[root] = true;
		res_friend += popular[root];
		res_cost += minCost[root];
	}
	if(res_friend == student && res_cost <= money) printf("%d\n", res_cost);
	else printf("Oh no\n");
}