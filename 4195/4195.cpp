#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int find(int idx, vector<int>& parents) {
    if(idx == parents[idx]) return idx;
    else return parents[idx] = find(parents[idx], parents);
}

void merge(int idxA, int idxB, vector<int>& parents, vector<int>& count) {
    int rootA = find(idxA, parents);
    int rootB = find(idxB, parents);
    if(rootA == rootB) return;
    else {
        parents[rootA] = rootB;
        count[rootB] += count[rootA];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int f, n = 0;
        scanf("%d", &f);
        map<string, int> names;
        vector<pair<string, string>> relations;
        for(int i=0; i<f; i++) {
            char name[2][22];
            scanf("%s %s", name[0], name[1]);
            relations.push_back(make_pair(name[0], name[1]));
            for(int j=0; j<2; j++) {
                if(names.find(name[j]) == names.end()) {
                    names.insert({name[j], n++});
                }
            }
        }
        vector<int> parents(n), count(n, 1);
        for(int i=0; i<n; i++) parents[i] = i;
        for(pair<string, string> name: relations) {
            int idxA = names.find(name.first)->second;
            int idxB = names.find(name.second)->second;
            merge(idxA, idxB, parents, count);
            printf("%d\n", count[find(idxA, parents)]);
        }
    }
}