#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int vertexNum, edgeNum, startPoint, endPoint;
vector<pair<int, int>> edge[1010];

vector<int> dijkstra(int src) {
	vector<int> dist(vertexNum+1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while(!pq.empty()) {
		int cost = -1 * pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < cost) continue;
		for(int i=0; i<edge[here].size(); i++) {
			int there = edge[here][i].first;
			int nextDist = edge[here][i].second + cost;
			if(dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-1 * nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	cin >> vertexNum >> edgeNum;
	for(int i=0; i<edgeNum; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back(make_pair(to, cost));
	}
	cin >> startPoint >> endPoint;
	vector<int> dist = dijkstra(startPoint);
	cout << dist[endPoint] << endl;
	// for(int i=1; i<dist.size(); i++) cout << dist[i] << " ";
	// cout << endl;
}