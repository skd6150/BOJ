#include <iostream>
#include <string>
using namespace std;

struct pos {
	int x;
	int y;
};

int find(pos des, pos cur, int size, int num) {
	if(size == 1) return num;
	int half = size / 2;
	if(des.y < cur.y + half) {
		if(des.x < cur.x + half) {
			return find(des, cur, half, num);
		}
		else {
			int num_diff = size * size / 4;
			cur.x += half;
			return find(des, cur, half, num + num_diff);
		}
	}
	else {
		if(des.x < cur.x + half) {
			int num_diff = size * size / 4 * 2;
			cur.y += half;
			return find(des, cur, half, num + num_diff);
		}
		else {
			int num_diff = size * size / 4 * 3;
			cur.x += half;
			cur.y += half;
			return find(des, cur, half, num + num_diff);
		}
	}
}

int main() {
	int N, size = 1;
	pos des;
	pos start = {0 , 0};
	cin >> N >> des.y >> des.x;
	for(int i=0; i<N; i++) size *= 2;
	cout << find(des, start, size, 0) << endl;
}