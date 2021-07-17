#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> stack;
vector<bool> store;
string input;
int len, t;

bool dfs(int curIdx) {
	int nextIdx = curIdx + t;
	if(nextIdx >= input.size() - t) {
		if(nextIdx >= input.size() || stack.back() == input[nextIdx]-'0') { 
			store = stack;
			return true;
		}
		else {
			return false;
		}
	}
	if(stack.back() == 0 && input[nextIdx] == '0') {
		stack.push_back(0);
		if(dfs(curIdx+2*t)) return true;
		else {
			stack.pop_back();
			return false;
		}
	}
	else if(stack.back() == 0 && input[nextIdx] == '1') {
		stack.push_back(1);
		if(dfs(curIdx+2*t)) return true;
		else {
			stack.pop_back();
			return false;
		}
	}
	else if(stack.back() == 1 && input[nextIdx] == '0') {
		return false;
	}
	else if(stack.back() == 1 && input[nextIdx] == '1') {
		stack.push_back(0); 
		if(dfs(curIdx+2*t)) return true;
		else {
			stack.pop_back();
			stack.push_back(1);
			if(dfs(curIdx+2*t)) return true;
			else {
				stack.pop_back();
				return false;
			}
		}
	}
	return false;
}

void solve() {
	bool res[50050];
	cin >> len >> t >> input;
	
	for(int i=0; i<t*2; i++) {
		if(i<t) {
			stack = vector<bool>();
			stack.push_back(0);
			bool dfsFlag = dfs(i);
			if(!dfsFlag) {
				stack = vector<bool>();
				stack.push_back(1);
				dfs(i);	
			}
		}
		else {
			if(input[i-t] == '0') {
				stack = vector<bool>();
				stack.push_back(0);
				dfs(i);
			}
			else if(input[i-t] == '1') {
				stack = vector<bool>();
				stack.push_back(1);
				dfs(i);
			}
		}
		for(int j=0; j<store.size(); j++) {
			res[i+j*2*t] = store[j];
		}
	}
	
	for(int i=0; i<input.size(); i++) cout << res[i];
	cout << endl;
	
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		cout << "Case #" << i+1 << endl;
		solve();
	}
}