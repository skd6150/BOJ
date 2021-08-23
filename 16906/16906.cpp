#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
	node* next[2];
	node* parent;
	bool alphabet;
	bool isRoot;
	int depth;
	bool flag;
	node(bool alphabet, node* parent) {
		isRoot = false;
		this->alphabet = alphabet;
		flag = false;
		next[0] = next[1] = nullptr;
		depth = parent->depth+1;
		this->parent = parent;
	}
	node() {
		isRoot = true;
		alphabet = 0;
		flag = false;
		next[0] = next[1] = nullptr;
		depth = 0;
		parent = nullptr;
	}
};

vector<bool> make_word(int len, node* root) {
	node* cur = root;
	bool flag = false;
	while(cur->depth != len) {
		if(cur->next[0] == nullptr) {
			cur->next[0] = new node(0, cur);
			cur = cur->next[0];
			if(cur->depth == len) cur->flag = true;
		}
		else if(!cur->next[0]->flag) {
			cur = cur->next[0];
		}
		else if(cur->next[1] == nullptr) {
			cur->next[1] = new node(1, cur);
			cur = cur->next[1];
			if(cur->depth == len) cur->flag = true;
		}
		else if(!cur->next[1]->flag) {
			cur = cur->next[1];
		}
		else if(cur->next[0]->flag && cur->next[1]->flag) {
			if(cur->isRoot) {
				flag = true;
				break;
			}
			cur->flag = true;
			cur = cur->parent;
		}
		//cout << "cur " << cur->depth << " " << cur->alphabet << endl;
	}
	if(flag) {
		return vector<bool>();
	}
	else {
		vector<bool> word;
		word.resize(len);
		while(!cur->isRoot) {
			word[--len] = cur->alphabet;
			cur = cur->parent;
		}
		return word;
	}
}

vector<int> ordered, sorted;
queue<vector<bool>> dict[1010];

int main() {
	int N;
	bool flag = false;
	node* root = new node();
	cin >> N;
	
	for(int i=0; i<N; i++) {
		int num;
		cin >> num;
		ordered.push_back(num);
		sorted.push_back(num);
	}
	
	sort(sorted.begin(), sorted.end());
	
	for(int i=0; i<N; i++) {
		int len = sorted[i];
		vector<bool> word = make_word(len, root);
		if(word.size() == 0) {
			flag = true;
			break;
		}
		else {
			dict[len].push(word);
		}
	}
	if(flag) {
		cout << "-1" << endl;
		return 0;
	}
	else {
		cout << "1" << endl;
		for(int i=0; i<N; i++) {
			vector<bool> word = dict[ordered[i]].front();
			dict[ordered[i]].pop();
			for(int j=0; j<word.size(); j++) cout << word[j];
			cout << endl;
		}
	}
}