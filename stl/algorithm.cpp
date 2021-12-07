#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for(int i: v) cout << i << " ";
    cout << endl;
}

vector<int> v = {5, 4, 3, 1, 2};

int main() {
    //sort
    // sort(v.begin(), v.end(), greater<int>()); // 내림차순
    sort(v.begin(), v.end()); // 내림차순

    // next permutation
    do {
        print(v);
    }while(next_permutation(v.begin(), v.end()));
    
    do {
        print(v);
    }while(prev_permutation(v.begin(), v.end()));


    // min max
    cout << min(1, 2) << endl;
    cout << max(1, 2) << endl;

    // min_element max_element
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << *max_element(v.begin(), v.end()) << endl;
    print(v);

    // swap
    int a = 1, b = 5;
    swap(a, b);
    cout << a << " " << b << endl;

    // lower_bound upper_bound
    v = {0, 1, 5, 6, 8};
    vector<int>::iterator iter;
    iter = lower_bound(v.begin(), v.end(), 3); // lower_bound: key가 있으면 key, 없으면 key보다 큰 값중 가장 작은값
    cout << *iter << endl;
    iter = upper_bound(v.begin(), v.end(), 3); // upper_bound: key를 초과하는 값 중 가장 작은값
    cout << *iter << endl;

    // binary_search
    cout << binary_search(v.begin(), v.end(), 3) << endl; // 3이 있으면 true
    cout << binary_search(v.begin(), v.end(), 9) << endl; // 9가 없으면 false
}