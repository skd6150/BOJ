#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int team, int size, vector<bool>& checked, vector<vector<bool>>& edges, vector<vector<int>>& teams) {
   teams[team].push_back(node);
   for(int i=1; i<=size; i++) {
      if(edges[node][i] && !checked[i]) {
         checked[i] = true;
         dfs(i, (team+1)%2, size, checked, edges, teams);
      }
   }
}

int main() {
   int n;
   cin >> n;
   vector<vector<bool>> edges(n+1, vector<bool>(n+1));
   vector<bool> checked(n+1);
   vector<vector<int>> teams(2);
   for(int i=1; i<=n; i++) {
      int len;
      cin >> len;
      for(int j=0; j<len; j++) {
         int p;
         cin >> p;
         edges[i][p] = edges[p][i] = true;
      }
   }

   for(int i=1; i<=n; i++) {
      if(checked[i]) continue;
      checked[i] = true;
      dfs(i, 0, n, checked, edges, teams);
   }

   for(int i=0; i<2; i++) {
      cout << teams[i].size() << endl;
      sort(teams[i].begin(), teams[i].end());
      for(int p: teams[i]) {
         cout << p << " ";
      }
      cout << endl;
   }
}