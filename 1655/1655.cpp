#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> minQueue;
	priority_queue<int, vector<int>, less<int>> maxQueue;
	
	int N;
	bool flag = true;
	scanf("%d", &N);
	while(N--) {
		int tmp;
		scanf("%d", &tmp);
		if(flag) maxQueue.push(tmp);
		else minQueue.push(tmp);
		flag = !flag;
		if(!minQueue.empty()) {
			if(maxQueue.top() > minQueue.top()) {
				int maxTop = maxQueue.top();
				int minTop = minQueue.top();
				maxQueue.pop();
				minQueue.pop();
				maxQueue.push(minTop);
				minQueue.push(maxTop);
			}	
		}
		printf("%d\n", maxQueue.top());
	}
}