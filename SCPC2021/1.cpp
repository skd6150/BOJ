#include <iostream>
#include <vector>

using namespace std;

int Answer;

void dfs(vector<vector<int>>& adj, vector<bool>& check, int cur) {
	check[cur] = true;
	for(int i=0; i<adj[cur].size(); i++) {
		if(!check[adj[cur][i]]) dfs(adj, check, adj[cur][i]);
	}
}

int solve() {
	int N, res = 0;
	cin >> N;
	vector<vector<int>> adj;
	vector<bool> check(N+10, false);
	adj.resize(N+10);
	for(int i=1; i<=N; i++) {
		int tmp;
		cin >> tmp;
		if(i+tmp > N) continue;
		adj[i].push_back(i+tmp);
		adj[i+tmp].push_back(i);
	}
	for(int i=1; i<=N; i++) {
		if(check[i]) continue;
		dfs(adj, check, i);
		res++;
	}
	return res;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = solve();
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}