#include <iostream>
#define MOD 1000000
using namespace std;

int main() {
	long long int day[1001][2][3];
	
	day[1][0][0] = 1;
	day[1][1][0] = 1;
	day[1][0][1] = 1;
	
	for(int i=2; i<=1000; i++) {
		day[i][0][0] = (day[i-1][0][0] + day[i-1][0][1] + day[i-1][0][2])%MOD;
		day[i][0][1] = (day[i-1][0][0])%MOD;
		day[i][0][2] = (day[i-1][0][1])%MOD;
		day[i][1][0] = (day[i-1][0][0] + day[i-1][0][1] + day[i-1][0][2] + day[i-1][1][0] + day[i-1][1][1] + day[i-1][1][2])%MOD;
		day[i][1][1] = (day[i-1][1][0])%MOD;
		day[i][1][2] = (day[i-1][1][1])%MOD;
	}
	
	int N;
	cin >> N;
	cout << (day[N][0][0]
			+day[N][0][1]
			+day[N][0][2]
			+day[N][1][0]
			+day[N][1][1]
			+day[N][1][2])%MOD << endl;
}