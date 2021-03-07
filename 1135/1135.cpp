#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
public:
	int idx;
	int time;
	node* superNode;
	vector<node*> subnodes;
	
	node(int idx, node* superNode) {
		this->idx = idx;
		this->superNode = superNode;
		this->time = -1;
	}
	bool hasChild() {
		return subnodes.size() != 0;
	}
	int numChild() {
		return subnodes.size();
	}
	void insert(node* subidx) {
		subnodes.push_back(subidx);
	}
};

node* employee[55];

bool cmp(int a, int b) {
	return a > b;
}

int call(node* somebody) {
	if(!somebody->hasChild()) return 0;
	vector<int> times;
	int max = -1;
	for(int i=0; i<somebody->subnodes.size(); i++) {
		int tmp = call(somebody->subnodes[i]) + 1;
		times.push_back(tmp);
	}
	sort(times.begin(), times.end(), cmp);
	for(int i=0; i<times.size(); i++) {
		times[i] += i;
		if(max < times[i]) max = times[i];
	}
	somebody->time = max;
	// cout << "call func " << somebody->idx << " " << max << endl;
	return max;
}

int main() {
	int N;
	employee[0] = new node(0, NULL);
	cin >> N;
	for(int i=0; i<N; i++) {
		int superIdx;
		cin >> superIdx;
		if(superIdx == -1) continue;
		employee[i] = new node(i, employee[superIdx]);
		employee[superIdx]->insert(employee[i]);
	}
	cout << call(employee[0]) << endl;
	
	// for(int i=0; i<N; i++) {
	// 	cout << employee[i]->time << " ";
	// }
	// cout << endl;
}