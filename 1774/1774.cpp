#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct edge {
   int from;
   int to;
   double dist;
};

bool cmp(edge A, edge B) {
   return A.dist < B.dist;
}

double getDist(int w, int h) {
   return sqrt((long long int)w*w + (long long int)h*h);
}

int find(int node, vector<int>& parents) {
   if(parents[node] == node) return node;
   return parents[node] = find(parents[node], parents);
}

void merge(int nodeA, int nodeB, vector<int>& parents) {
   int rootA = find(nodeA, parents);
   int rootB = find(nodeB, parents);
   if(rootA == rootB) return;
   else parents[rootA] = rootB;
}

int main() {
   int n, m;
   double result = 0;
   cin >> n >> m;
   vector<pair<int, int>> pos(n+1);
   vector<edge> edges(n+1);
   vector<int> parents(n+1);

   for(int i=1; i<=n; i++) {
      int x, y;
      cin >> x >> y;
      pos[i] = {x, y};
      parents[i] = i;
   }
   
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         if(i == j) continue;
         edges.push_back({i, j, getDist(pos[i].first - pos[j].first, pos[i].second - pos[j].second)});
      }
   }
   sort(edges.begin(), edges.end(), cmp);

   for(int i=0; i<m; i++) {
      int p, q;
      cin >> p >> q;
      merge(p, q, parents);
   }

   for(edge e: edges) {
      if(find(e.from, parents) == find(e.to, parents)) continue;
      result += e.dist;
      merge(e.from, e.to, parents);
   }

   cout << fixed << setprecision(2) << result << endl;
}