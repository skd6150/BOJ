#include <iostream>
#include <vector>
using namespace std;

struct node {
    int parent;
    vector<int> children;
};

int find(int n, vector<node>& tree) {
    if(tree[n].children.size() == 0 || (tree[n].children.size() == 1 && tree[n].children[0] == -100)) {
        // cout << "leaf " << n << endl;
        return 1;
    } 

    int result = 0;
    for(int next: tree[n].children) {
        if(next == -100) continue;
        result += find(next, tree);
    }
    return result;
}

int main() {
    int n, del, root, leaf = 0;
    cin >> n;
    vector<node> tree;
    tree.assign(n+10, {-1, vector<int>()});
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == -1) root = i;
        tree[i].parent = tmp;
        if(tmp != -1) {
            tree[tmp].children.push_back(i);
        }
    }

    cin >> del;
    if(del == root) {
        cout << 0 << endl;
    }
    else {
        for(int i=0; i<tree[tree[del].parent].children.size(); i++) {
           if(tree[tree[del].parent].children[i] == del) tree[tree[del].parent].children[i] = -100;
        }
        cout << find(root, tree) << endl;
    }
}