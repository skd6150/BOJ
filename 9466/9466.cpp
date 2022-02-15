#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--) {
        int v, team = 0;
        cin >> v;
        vector<int> points;
        vector<int> visited(v, -1);
        for(int i=0; i<v; i++) {
            int tmp;
            cin >> tmp;
            points.push_back(tmp-1);
        }
        for(int i=0; i<v; i++) {
            if(visited[i] != -1) continue;
            stack<int> s;
            int cur = i;
            int startPoint;
            while(true) {
                s.push(cur);
                if(visited[cur] != -1) break;
                visited[cur] = i;
                cur = points[cur];
            }
            if(visited[s.top()] != i) continue;
            startPoint = s.top();
            while(true) {
                team++;
                s.pop();
                if(s.top() == startPoint) break;
            }
        }
        cout << v - team << endl;
    }
}