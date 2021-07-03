#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<bool> gear[4];
int query;

void spinClockWise(int gearIdx) {
	bool tmp = gear[gearIdx].back();
	gear[gearIdx].pop_back();
	gear[gearIdx].push_front(tmp);
}
void spinCounterClockWise(int gearIdx) {
	bool tmp = gear[gearIdx].front();
	gear[gearIdx].pop_front();
	gear[gearIdx].push_back(tmp);
}
void spinGear(int gearIdx, int clockwise) {
	int spinSchedule[4] = {0, 0, 0, 0};
	spinSchedule[gearIdx] = clockwise;
	
	for(int i=gearIdx; i>0; i--) {
		if(gear[i][6] != gear[i-1][2]) {
			spinSchedule[i-1] = -1 * spinSchedule[i];
		}
	}
	for(int i=gearIdx; i<3; i++) {
		if(gear[i][2] != gear[i+1][6]) {
			spinSchedule[i+1] = -1 * spinSchedule[i];
		}
	}
	for(int i=0; i<4; i++) {
		if(spinSchedule[i] == 0) continue;
		if(spinSchedule[i] == 1) spinClockWise(i);
		if(spinSchedule[i] == -1) spinCounterClockWise(i);
	}
	
}

int main() {
	int res = 0, score = 1;
	for(int i=0; i<4; i++) {
		string input;
		cin >> input;
		for(int j=0; j<8; j++) {
			gear[i].push_back((input[j] == '1'));	
		}
	}
	
	cin >> query;
	for(int i=0; i<query; i++) {
		int gearIdx, clockwise;
		cin >> gearIdx >> clockwise;
		spinGear(gearIdx-1, clockwise);
	}
	for(int i=0; i<4; i++) {
		if(gear[i][0]) res += score;
		score *= 2;
	}
	cout << res << endl;
}