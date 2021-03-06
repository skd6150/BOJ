#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dp[1000011];
int top, start, dest, up, down;
queue<pair<int ,int>> Q;

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> top >> start >> dest >> up >> down;
	Q.push(make_pair(start, 0));
	while(!Q.empty()) {
		int cur = Q.front().first;
		int score = Q.front().second;
		Q.pop();
		if(cur > top || cur <= 0) continue;
		if(dp[cur] != -1) continue;
		dp[cur] = score;
		if(up != 0) Q.push(make_pair(cur+up, score+1));
		if(down != 0) Q.push(make_pair(cur-down, score+1));
	}
	
	// for(int i=1; i<=top; i++) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	
	if(dp[dest] == -1) {
		cout << "use the stairs" << endl;
	}
	else cout << dp[dest] << endl;
}