#include <iostream>
using namespace std;

long long int arr[100010];
long long int absolute(long long int a) {
	return a > 0 ? a : -a;
}

int main() {
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &arr[i]);
	
	long long int min = 98765432100;
	int i=0, j=N-1, idx[2];
	while(i != j) {
		long long int combine = arr[i] + arr[j];
		if(absolute(combine) <= min) {
			min = absolute(combine);
			idx[0] = i;
			idx[1] = j;
		}
		if(combine > 0) j--;
		else i++;
	}
	cout << arr[idx[0]] << " " << arr[idx[1]] << endl;
}