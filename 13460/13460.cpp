#include <iostream>
#include <string>
using namespace std;

struct pos {
	int y;
	int x;
};

int height, width;
char field[10][10];
int ret = 10;
bool reachable = false;

int min(int a, int b) {
	return (a<b) ? a : b;
}
bool same(pos a, pos b) {
	if(a.y == b.y && a.x == b.x) return true;
	else return false;
}
bool isMovable(int i, int j) {
	if(field[i][j] == '#') return false;
	if(i<0 || j<0 || i>=height || j>=width) return false;
	return true;
}

void moveBalls(pos red, pos blue, int count, int past) {
	if(count > ret) return;
	pos diff[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	for(int i=0; i<4; i++) {
		bool freeze = false;
		bool redRolling = true;
		bool blueRolling = true;
		bool blueGoal = false;
		bool redGoal = false;
		pos nextRed = red;
		pos nextBlue = blue;
		while(redRolling || blueRolling) {
			pos curRed = nextRed;
			pos curBlue = nextBlue;
			if(redRolling) {
				nextRed.y += diff[i].y;
				nextRed.x += diff[i].x;
				if(!isMovable(nextRed.y, nextRed.x)) {
					nextRed = curRed;
					redRolling = false;
				}
			}
			if(blueRolling) {
				nextBlue.y += diff[i].y;
				nextBlue.x += diff[i].x;
				if(!isMovable(nextBlue.y, nextBlue.x)) {
					nextBlue = curBlue;
					blueRolling = false;
				}
			}
			if(nextRed.y == nextBlue.y && nextRed.x == nextBlue.x) {
				nextRed = curRed;
				nextBlue = curBlue;
				break;
			}
			if(field[nextBlue.y][nextBlue.x] == 'O') {
				blueGoal = true;
				nextBlue = {-1, -1};
			}
			if(field[nextRed.y][nextRed.x] == 'O') {
				redGoal = true;
				nextRed = {-1, -1};
			}
		}
		if(blueGoal) {
			freeze = true;
		}
		else if(redGoal) {
			reachable = true;
			ret = min(ret, count);
			freeze = true;
		}
		if(same(nextRed, red) && same(nextBlue, blue)) freeze = true;
		if(!freeze) {
			moveBalls(nextRed, nextBlue, count+1, 3-i);
		}
	}
}

int main() {
	pos redInit, blueInit;
	cin >> height >> width;
	for(int i=0; i<height; i++) {
		string tmp;
		cin >> tmp;
		for(int j=0; j<width; j++) {
			field[i][j] = tmp[j];
			if(field[i][j] == 'B') {
				blueInit = {i ,j};
				field[i][j] == '.';
			}
			if(field[i][j] == 'R') {
				redInit = {i ,j};
				field[i][j] == '.';
			}
		}
	}
	moveBalls(redInit, blueInit, 1, -1);
	if(!reachable) cout << "-1" << endl;
	else cout << ret << endl;
}