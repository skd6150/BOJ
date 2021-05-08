#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct quiz {
	int deadline;
	int prize;
};

bool cmp(quiz a, quiz b) {
	if(a.deadline == b.deadline) return a.prize > b.prize;
	return a.deadline > b.deadline;
}

int main() {
	quiz homework[200200];
	int N, res = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int deadline, prize;
		scanf("%d %d", &deadline, &prize);
		homework[i] = {deadline, prize};
	}
	sort(homework, homework+N, cmp);
	
	priority_queue<int> pq;
	int time = N, idx = 0;
	while(time) {
		for(; idx<N && homework[idx].deadline == time; idx++) {
			pq.push(homework[idx].prize);
		}
		if(!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
		time--;
	}
	
	printf("%d\n", res);
}