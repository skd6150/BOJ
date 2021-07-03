#include <iostream>
#include <memory.h>
using namespace std;

int width, height, T;
int dust[55][55];
int cleaner[2];

bool isSpreadable(int i, int j) {
	if(dust[i][j] == -1) return false;
	if(i < 0 || j < 0 || i >= height || j >= width) return false;
	return true;
}

void spreadDust() {
	int dustDiff[55][55];
	memset(dustDiff, 0, sizeof(dustDiff));
	for(int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			if(dust[i][j] > 0) {
				int total = dust[i][j];
				int spreadCount = 0;
				if(isSpreadable(i-1, j)) {
					dustDiff[i-1][j] += total/5;
					spreadCount++;
				}
				if(isSpreadable(i+1, j)) {
					dustDiff[i+1][j] += total/5;
					spreadCount++;
				}
				if(isSpreadable(i, j-1)) {
					dustDiff[i][j-1] += total/5;
					spreadCount++;
				}
				if(isSpreadable(i, j+1)) {
					dustDiff[i][j+1] += total/5;
					spreadCount++;
				}
				dustDiff[i][j] -= (total/5)*spreadCount;
			}
		}
	}
	for(int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			dust[i][j] += dustDiff[i][j];
		}
	}
}
void cleaning() {
	for(int i=cleaner[0]-1; i>0; i--) {
		dust[i][0] = dust[i-1][0];
	}
	for(int i=0; i<width-1; i++) {
		dust[0][i] = dust[0][i+1];
	}
	for(int i=0; i<cleaner[0]; i++) {
		dust[i][width-1] = dust[i+1][width-1];
	}
	for(int i=width-1; i>1; i--) {
		dust[cleaner[0]][i] = dust[cleaner[0]][i-1];
	}
	dust[cleaner[0]][1] = 0;
	
	for(int i=cleaner[1]+1; i<height-1; i++) {
		dust[i][0] = dust[i+1][0];
	}
	for(int i=0; i<width-1; i++) {
		dust[height-1][i] = dust[height-1][i+1];
	}
	for(int i=height-1; i>cleaner[1]; i--) {
		dust[i][width-1] = dust[i-1][width-1];
	}
	for(int i=width-1; i>1; i--) {
		dust[cleaner[1]][i] = dust[cleaner[1]][i-1];
	}
	dust[cleaner[1]][1] = 0;
}

int main() {
	int cleanerIdx=0, res = 0;
	cin >> height >> width >> T;
	for(int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			cin >> dust[i][j];
			if(dust[i][j] == -1) cleaner[cleanerIdx++] = i;
		}
	}
	while(T--) {
		spreadDust();
		cleaning();
		
	}
	for(int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			res += dust[i][j];
		}
	}
	cout << res+2 << endl;
}