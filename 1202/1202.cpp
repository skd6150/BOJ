#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct jewel {
	int weight;
	int price;
};

bool cmp(jewel a, jewel b) {
	if(a.weight == b.weight) return a.price < b.price;
	return a.weight < b.weight;
}

jewel arr[300300];
int bag[300300];

int main() {
	int N, K;
	long long int res=0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &arr[i].weight, &arr[i].price);
	}
	for(int i=0; i<K; i++) {
		scanf("%d", &bag[i]);
	}
	sort(arr, arr+N, cmp);
	sort(bag, bag+K);
	
	priority_queue<int> pq;
	int idx = 0;
	for(int i=0; i<K; i++) {
		int cur = bag[i];
		for(; idx<N && arr[idx].weight<=cur; idx++) {
			pq.push(arr[idx].price);
			//cout << "pq push " << arr[idx].price << " " << cur << endl;
		}
		if(!pq.empty()) {
			//cout << "put " << cur << " " << pq.top() << endl;
			res+=pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", res);
}