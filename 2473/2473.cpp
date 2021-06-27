#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[5005];

int find(int start, int end, long long int goal) {
	if(start == end) return start;
	int mid = (start + end) / 2;
	if(arr[mid] == goal) return mid;
	if(arr[mid] > goal) {
		return find(start, mid, goal);
	}
	else {
		return find(mid+1, end, goal);
	}
}

int main() {
	int N;
	int resIdx[3];
	long long int res = 9876543210;
	cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i];
	sort(arr, arr+N);
	
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(i==j) continue;
			long long int compound2 = arr[i] + arr[j];
			int idx = find(0, N-1, -1*compound2);
			for(int k=-1; k<=1; k++) {
				if(idx+k == i || idx+k == j) continue;
				if(idx+k < 0 || idx+k >= N) continue;
				long long int compound3 = compound2 + arr[idx+k];
				if(abs(compound3) < res) {
					res = abs(compound3);
					resIdx[0] = arr[i];
					resIdx[1] = arr[j];
					resIdx[2] = arr[idx+k];
				}
			}
		}
	}
	sort(resIdx, resIdx+3);
	for(int i=0; i<3; i++) cout << resIdx[i] << " ";
	cout << endl;
}