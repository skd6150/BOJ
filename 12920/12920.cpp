#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> objects;
int dp[10100];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}
	else return a.first < b.first;
}
int min(int a, int b) {
	return a > b ? b : a;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, M, sumWeight = 0;
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		int weight, value, count;
		cin >> weight >> value >> count;
		sumWeight += weight * count;
		for(int j=1; count>0; j*=2) {
			int coef = min(j, count);
			objects.push_back(make_pair(weight*coef, value*coef));
			count -= coef;
		}
	}
	sort(objects.begin(), objects.end(), cmp);
	sumWeight = min(sumWeight, 10010);
	for(int i=0; i<objects.size(); i++) {
		int curWeight = objects[i].first;
		int curValue = objects[i].second;
		for(int j=sumWeight; j>=curWeight; j--) {
			dp[j] = max(dp[j], dp[j-curWeight]+curValue);
		}
	}
	if(sumWeight < M) {
		cout << dp[sumWeight] << endl;
	}
	else {
		cout << dp[M] << endl;	
	}
}