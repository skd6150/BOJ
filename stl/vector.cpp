#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3}; // [1, 2, 3]으로 초기화
    vector<int> v2(5); // 5개의 원소를 0으로 초기화
    vector<int> v3(5, 3); // 5개 원소를 3으로 초기화

    v2.size(); // 값이 들어있는 개수
    v2.capacity(); // 물리적 크기

    v1.push_back(4); // 맨 뒤에 원소 추가
    v1.pop_back(); // 맨 뒤 원소 삭제

    v1.front(); // 맨 앞 원소
    v1.back(); // 맨 뒤 원소
}