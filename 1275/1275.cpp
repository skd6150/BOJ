#include <iostream>
using namespace std;

long long int segtree[266666];
long long int input[100010];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

long long int init(int node, int start, int end) {
	if(start == end) {
		return segtree[node] = input[start];
	}
	else {
		return segtree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
	}
}

long long int sum(int node, int start, int end, int left, int right) {
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return segtree[node];
	return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

void update(int node, int start, int end, int idx, long long int diff) {
	if(idx < start || idx > end) return;
	segtree[node] += diff;
	if(start != end) {
		update(node*2, start, (start+end)/2, idx, diff);
		update(node*2+1, (start+end)/2+1, end, idx, diff);
	}
}

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++) scanf("%lld", &input[i]);
	init(1, 0, N-1);
	
	while(Q--) {
		//for(int i=1; i<N*2; i++) cout << segtree[i] << " "; cout << endl;
		int start, end, where;
		long long int num;
		scanf("%d %d %d %lld", &start, &end, &where, &num);
		if(start > end) swap(start, end);
		long long int diff = num - input[where-1];
		input[where-1] = num;
		printf("%lld\n", sum(1, 0, N-1, start-1, end-1));
		update(1, 0, N-1, where-1, diff);
	}
}