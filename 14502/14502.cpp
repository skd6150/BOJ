#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int width, height;
int field[8][8];
vector<pair<int, int>> emptySpace;
vector<bool> permutationArr;
vector<pair<int, int>> virus;
int res = -1;

bool isInRange(int i, int j) {
	if(i < 0 || j < 0 || i >= height || j >= width) return false;
	return true;
}

void BFS(int fieldTmp[][8], bool visited[][8], pair<int, int> pos) {
	queue<pair<int, int>> Q;
	Q.push(pos);
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		int i = cur.first;
		int j = cur.second;
		if(isInRange(i+1, j) && !visited[i+1][j] && fieldTmp[i+1][j] == 0) {
			visited[i+1][j] = true;
			Q.push(make_pair(i+1,j));
		}
		if(isInRange(i-1, j) && !visited[i-1][j] && fieldTmp[i-1][j] == 0) {
			visited[i-1][j] = true;
			Q.push(make_pair(i-1,j));
		}
		if(isInRange(i, j+1) && !visited[i][j+1] && fieldTmp[i][j+1] == 0) {
			visited[i][j+1] = true;
			Q.push(make_pair(i,j+1));
		}
		if(isInRange(i, j-1) && !visited[i][j-1] && fieldTmp[i][j-1] == 0) {
			visited[i][j-1] = true;
			Q.push(make_pair(i,j-1));
		}
	}
	return;
}

int main() {
	cin >> height >> width;
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			cin >> field[i][j];
			if(field[i][j] == 0) emptySpace.push_back(make_pair(i, j));
			if(field[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	
	permutationArr = vector<bool>(emptySpace.size()-3, false);
	for(int i=0; i<3; i++) permutationArr.push_back(true);
	
	do {
		// for(int i=0; i<permutationArr.size(); i++) cout << permutationArr[i];
		// cout << endl;
		
		int fieldTmp[8][8];
		bool visited[8][8];
		vector<pair<int, int>> wall;
		int safeZone = 0;
		
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				fieldTmp[i][j] = field[i][j];
			}
		}
		for(int i=0; i<permutationArr.size(); i++) {
			if(permutationArr[i]) wall.push_back(emptySpace[i]);
		}
		for(int i=0; i<3; i++) {
			fieldTmp[wall[i].first][wall[i].second] = 1;
		}
		for(int i=0; i<virus.size(); i++) {
			BFS(fieldTmp, visited, virus[i]);
		}
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if(fieldTmp[i][j] == 0 && !visited[i][j]) safeZone++;
			}
		}
		if(res < safeZone) res = safeZone;
		if(safeZone == emptySpace.size() - 3) break;
	} while(next_permutation(permutationArr.begin(), permutationArr.end()));
	cout << res << endl;
}