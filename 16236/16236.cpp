#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

struct pos {
	int x;
	int y;
};
struct fish {
	pos position;
	int dist;
};
int field[22][22];
int fieldSize, sharkSize = 2, T = 0;
pos sharkPos;

bool cmp(fish a, fish b) {
	if(a.dist == b.dist) {
		if(a.position.x == b.position.x) {
			return a.position.y < b.position.y;
		}
		return a.position.x < b.position.x;
	}
	return a.dist < b.dist;
}

bool isInRange(int i, int j) {
	if(i < 0 || j < 0 || i >= fieldSize || j >= fieldSize) return false;
	return true;
}

vector<fish> findFishes() {
	queue<fish> Q;
	vector<fish> V;
	bool visited[fieldSize][fieldSize];
	memset(visited, 0, sizeof(visited));
	Q.push({sharkPos, 0});
	visited[sharkPos.x][sharkPos.y] = true;
	while(!Q.empty()) {
		fish cur = Q.front();
		int x = cur.position.x;
		int y = cur.position.y;
		if(field[x][y] < sharkSize && field[x][y] > 0 && field[x][y] != 9) V.push_back(cur);
		Q.pop();
		if(isInRange(x+1, y) && !visited[x+1][y] && field[x+1][y] <= sharkSize) {
			Q.push({{x+1, y}, cur.dist+1});
			visited[x+1][y] = true;
		}
		if(isInRange(x-1, y) && !visited[x-1][y] && field[x-1][y] <= sharkSize) {
			Q.push({{x-1, y}, cur.dist+1});
			visited[x-1][y] = true;
		}
		if(isInRange(x, y+1) && !visited[x][y+1] && field[x][y+1] <= sharkSize) {
			Q.push({{x, y+1}, cur.dist+1});
			visited[x][y+1] = true;
		}
		if(isInRange(x, y-1) && !visited[x][y-1] && field[x][y-1] <= sharkSize) {
			Q.push({{x, y-1}, cur.dist+1});
			visited[x][y-1] = true;
		}
	}
	sort(V.begin(), V.end(), cmp);
	return V;
}

int main() {	
	cin >> fieldSize;
	for(int i=0; i<fieldSize; i++) {
		for(int j=0; j<fieldSize; j++) {
			cin >> field[i][j];
			if(field[i][j] == 9) sharkPos = {i, j};
		}
	}
	
	int fishCount=0;
	while(true) {
		//cout << sharkPos.x << " " << sharkPos.y << endl;
		vector<fish> eatableFishes = findFishes();
		field[sharkPos.x][sharkPos.y] = 0;
		if(eatableFishes.size() == 0) break;
		fish next = eatableFishes[0];
		T += next.dist;
		sharkPos = next.position;
		fishCount++;
		if(fishCount == sharkSize) {
			fishCount = 0;
			sharkSize++;
		}
		field[next.position.x][next.position.y] = 9;
	}
	cout << T << endl;
}