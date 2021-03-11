#include <iostream>
#include <vector>
using namespace std;

int dp[20];
long long int N, target;
vector<char> save;

int tree(long long int idx, long long int right, vector<char> nodes) {
	if(!nodes.size()) return idx;
	if(nodes.size() == 1) {
		save.push_back(nodes[0]);
		return idx;
	}
	int length = nodes.size();
	long long int dist = 0, root_idx;
	char root;
	vector<char> smaller_nodes, bigger_nodes;
	for(int i=0; i<length; i++) {
		int tmp = dist;
		dist += dp[i] * dp[length - i - 1] * right;
		if(idx + dist >= target) {
			dist = tmp;
			root_idx = i;
			root = nodes[i];
			break;
		}
	}
	save.push_back(root);
	for(int i=0; i<root_idx; i++) smaller_nodes.push_back(nodes[i]);
	for(int i=root_idx+1; i<length; i++) bigger_nodes.push_back(nodes[i]);
	int new_right = right * dp[bigger_nodes.size()];
	
	idx += dist;
	if(smaller_nodes.size()) idx = tree(idx, new_right, smaller_nodes);
	if(bigger_nodes.size()) idx = tree(idx, right, bigger_nodes);
	return idx;
}


int main() {
	vector<char> rest;
	cin >> N >> target;
	dp[0] = dp[1] = 1;
	for(int i=2; i<20; i++) {
		int ret = 0;
		for(int j=0; j<i; j++) {
			ret += dp[i - j - 1]*dp[j];
		}
		dp[i] = ret;
	}
	if(target > dp[N]) {
		cout << -1 << endl;
	} 
	else {
		for(int i=0; i<N; i++) {
			rest.push_back((char)('a'+i));
		}
		// cout << "result: " << tree(0, dp[0], rest) <<endl;
		tree(0, dp[0], rest);
		for(int i=0; i<N; i++) {
			cout << save[i];
		}
		cout << endl;
	}
}