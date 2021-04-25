#include <iostream>
#include <string>
using namespace std;

int main() {
	int pi[1000000];
	int size;
	string text;
	cin >> size >> text;
	
	int begin = 1, matched = 0;
	while(begin + matched < size) {
		if(text[begin + matched] == text[matched]) {
			matched++;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	
	cout << size - pi[size-1] << endl;
}