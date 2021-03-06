#include <iostream>
#include <algorithm>
using namespace std;

struct line {
	int x;
	int y;
};

bool cmp(line a, line b) {
	return (a.x < b.x) ? true : false;
}

int max(int a, int b) {
	return (a>b) ? a : b;
}

int main() {
	int N, len = 0, y_tmp;
	line arr[100011];
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr+N, cmp);
	
	for(int i=0; i<N; i++) {
		if(i==0) {
			len += arr[i].y - arr[i].x;
			y_tmp = arr[i].y;
		}
		else {
			if(y_tmp > arr[i].y) continue;
			int x = max(y_tmp, arr[i].x);
			len += arr[i].y - x;
			y_tmp = arr[i].y;
		}
	}
	cout << len << endl;
}