#include <iostream>
#include <algorithm>
using namespace std;

class PQ {
public:
	int size;
	long long int heap[100011];
	PQ() {
		size = 0;
	}
	void insert(int card) {
		int idx = ++size;
		heap[idx] = card;
		while((idx!=1) && (heap[idx] < heap[idx/2])) {
			heap[idx] = heap[idx/2];
			heap[idx/2] = card;
			idx /= 2;
		}
	}
	long long int pop() {
		int res = heap[1];
		int idx = 1;
		int child = 2;
		heap[idx] = heap[size--];
		while(child <= size) {
			if(child < size && (heap[child] > heap[child+1])) {
				child++;
			}
			if(heap[idx] < heap[child]) {
				break;
			}
			int tmp = heap[idx];
			heap[idx] = heap[child];
			heap[child] = tmp;
			idx = child;
			child *= 2;
			
		}
		return res;
	}
	bool empty() {
		return size==0;
	}
	void print() {
		for(int i=1; i<=size; i++) cout << heap[i] << endl;
		cout << endl;
	}
};

int main() {
	long long int res = 0;
	int N;
	PQ cards;
	cin >> N;
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		cards.insert(tmp);
	}
	while(!cards.empty()) {
		long long int tmp = 0;
		if(cards.size >= 2) {
			long long int cardA = cards.pop();
			long long int cardB = cards.pop();
			// cout << cardA << "+" << cardB << endl;
			tmp += cardA + cardB;
			cards.insert(tmp);
			res += tmp;
		}
		else break;
	}
	cout << res << endl;
}