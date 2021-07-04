#include <iostream>
using namespace std;

int dice[6];
int height, width;
int map[22][22];

bool isInRange(int i, int j) {
	if(i < 0 || j < 0 || i >= height || j >= width) return false;
	return true;
}

void copy(int& dice, int& map) {
	if(map == 0) {
		map = dice;
	}
	else {
		dice = map;
		map = 0;
	}
}

void roll(int direction) {
	int diceTmp[6];
	for(int i=0; i<6; i++) diceTmp[i] = dice[i];
	switch(direction) {
		case 1: //E
			dice[3] = diceTmp[0];
			dice[0] = diceTmp[2];
			dice[5] = diceTmp[3];
			dice[2] = diceTmp[5];
			break;
		case 2: //W
			dice[2] = diceTmp[0];
			dice[5] = diceTmp[2];
			dice[0] = diceTmp[3];
			dice[3] = diceTmp[5];
			break;
		case 3: //S
			dice[1] = diceTmp[0];
			dice[5] = diceTmp[1];
			dice[0] = diceTmp[4];
			dice[4] = diceTmp[5];
			break;
		case 4: //N
			dice[4] = diceTmp[0];
			dice[0] = diceTmp[1];
			dice[5] = diceTmp[4];
			dice[1] = diceTmp[5];
			break;
	}
}

int main() {
	int x, y, query;
	cin >> height >> width >> x >> y >> query;
	
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			cin >> map[i][j];
		}
	}
	copy(dice[0], map[x][y]);
	while(query--) {
		int next, nextX = x, nextY = y;
		cin >> next;
		switch(next) {
			case 1:
				nextY++;
				break;
			case 2:
				nextY--;
				break;
			case 3:
				nextX--;
				break;
			case 4:
				nextX++;
				break;
		}
		if(!isInRange(nextX, nextY)) continue;
		x = nextX; y = nextY;
		roll(next);
		copy(dice[0], map[x][y]);
		cout << dice[5] << endl;
	}
}