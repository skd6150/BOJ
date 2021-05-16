#include <iostream>
#define N 1000100
using namespace std;

int parent[N], level[N];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int find(int node) {
	if(parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(level[a] > level[b]) swap(a, b);
	if(level[a] == level[b]) level[b]++;
	parent[a] = b;
}

int main() {
	int num, query;
	scanf("%d %d", &num, &query);
	
	for(int i=0; i<N; i++) {
		parent[i] = i;
	}
	
	for(int i=0; i<query; i++) {
		int flag, a, b;
		scanf("%d %d %d", &flag, &a, &b);
		if(flag == 1) {
			if(find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else {			
			merge(a, b);
		}
	}
}