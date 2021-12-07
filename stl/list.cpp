#include <iostream>
#include <list>

using namespace std;

int main() {
    // list: doubly linked list
    list<int> list1; // empty list
    list<int> list2(3); // {0, 0, 0}
    list<int> list3(5, 3); // {3, 3, 3, 3, 3}

    list1.front(); // 맨 처음 원소
    list1.back(); // 맨 마지막 원소

    list<int>::iterator it;
    it = list1.begin(); // 맨 처음 원소를 가르키는 iterator
    it = list1.end(); // 맨 마지막 원소 바로 뒤를 가르키는 iterator
    advance(it, 3); // it를 3칸 뒤로 이동

    list1.push_back(1); // 맨 뒤에 1 추가
    list1.push_front(2); // 맨 앞에 2추가
    list1.pop_back(); // 맨 뒤 원소 제거
    list1.pop_front(); // 맨 앞 원소 제거

    it = list1.begin();
    list1.erase(it); // it가 가르키는 원소 제거

    list1.remove(2); // list에서 모든 2 제거
    
}