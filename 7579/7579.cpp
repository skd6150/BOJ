#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, costSum = 0;
pair<int, int> app[110];
int dp[10100];

int max(int a, int b) {
	return a > b ? a : b;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}
	else return a.first < b.first;
}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> app[i].second;
	}
	for(int i=0; i<N; i++) {
		cin >> app[i].first;
		costSum += app[i].first;
	}
	sort(app, app+N, cmp);
	
	for(int i=0; i<N; i++) {
		int curMemory = app[i].second;
		int curCost = app[i].first;
		for(int j=costSum; j>=curCost; j--) {
			dp[j] = max(dp[j], dp[j-curCost]+curMemory);
		}
	}
	for(int i=0; i<=costSum; i++) {
		if(dp[i] >= M) {
			cout << i << endl;
			break;
		}
	}
}