#include <iostream>
#define N 30
using namespace std;

long long int tiles[N+1];
long long int symmetry[N+1];

int main() {
	tiles[1] = 1;
	tiles[2] = 3;
	for(int i=3; i<=N; i++) {
		tiles[i] = tiles[i-1] + tiles[i-2]*2;
	}
	
	symmetry[1] = 1;
	symmetry[2] = 3;
	for(int i=3; i<=N; i++) {
		if(i%2) { //odd
			symmetry[i] = tiles[(i-1)/2];
		}
		else {
			symmetry[i] = tiles[i/2] + 2*tiles[(i-2)/2];
		}
	}
	
	int n;
	cin >> n;
	cout << (tiles[n] + symmetry[n])/2 << endl;
}