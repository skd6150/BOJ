#include <iostream>
#include <utility>
using namespace std;
//https://jason9319.tistory.com/358

pair<pair<int, int>, pair<int, int>> lines[3030];
int parent[3030];
int tsize[3030];
int level[3030];
bool visit[3030];

int max(int a, int b) {
	return (a>b)?a:b;
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = a.second*(b.first-c.first)-b.second*(a.first-c.first)+c.second*(a.first-b.first);
	if(op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

int isIntersection(pair<int, int> a, pair<int, int> b, pair<int, int>c, pair<int, int>d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d ,b);
	if(ab == 0 && cd == 0) {
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		return c<=b && a<=d;
	}
	return ab<=0 && cd<=0;
}

int find(int node) {
	if(node == parent[node]) return node;
	return parent[node] = find(parent[node]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return;
	if(level[u] > level[v]) swap(u, v);
	parent[u] = v;
	tsize[v] += tsize[u];
	if(level[u] == level[v]) level[v]++;
}

int main() {
	int N, res_group = 0, res_max = 0;
	cin >> N;
	for(int i=0; i<N; i++) {
		pair<int, int> a, b;
		cin >> a.first >> a.second >> b.first >> b.second;
		//scanf("%d %d %d %d", &a.first, &a.second, &b.first, &b.second);
		lines[i].first = a;
		lines[i].second = b;
	}
	for(int i=0; i<N; i++) {
		parent[i] = i;
		tsize[i] = 1;
	}
	for(int i=0; i<N; i++) {
		pair<pair<int, int>, pair<int, int>> cur = lines[i];
		for(int j=i; j<N; j++) {
			if(i==j) continue;
			bool flag = isIntersection(cur.first, cur.second, lines[j].first, lines[j].second);
			if(flag) {
				merge(i, j);
				//break;
			}
		}
	}
	for(int i=0; i<N; i++) {
		int root = find(i);
		if(visit[root]) continue;
		visit[root] = true;
		res_group++;
		res_max = max(res_max, tsize[root]);
	}
	
	cout << res_group << endl << res_max << endl;
}