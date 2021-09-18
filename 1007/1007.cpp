#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

double vectorSize(double x, double y) {
	return sqrt(x*x + y*y);
}

double vectorMatching(vector<pair<double, double>> V) {
	int len = V.size();
	double min = 9876543210;
	vector<bool> combination(len, false);
	for(int i=len/2; i<len; i++) combination[i] = true;
	do {
		double x = 0, y = 0; 
		for(int i=0; i<len; i++) {
			if(combination[i]) {
				x += V[i].first;
				y += V[i].second;
			}
			else {
				x -= V[i].first;
				y -= V[i].second;
			}
		}
		double size = vectorSize(x, y);
		if(min > size) min = size;
	}while(!combination[0] && next_permutation(combination.begin(), combination.end()));
	return min;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<pair<double, double>> V;
		for(int i=0; i<N; i++) {
			double x, y;
			cin >> x >> y;
			V.push_back(make_pair(x, y));
		}
		
		cout.precision(12);
		cout << fixed << vectorMatching(V) << endl;
	}
}