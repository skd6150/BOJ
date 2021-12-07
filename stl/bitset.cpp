#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<5> bit;
    
    bit.reset(); // 전체 비트 0으로 초기화
    cout << bit << endl;

    bit.set(); // 전체 비트 1로 초기화
    cout << bit << endl;

    bit.set(2, false); // 2번째 비트 false로 수정
    cout << bit << endl;

    bool flag = bit[2]; // 임의접근으로
    cout << flag << endl;

    bit.flip(); // 전체 비트 반전

    cout << bit.any() << endl; // 하나라도 1이면 true
    cout << bit.none() << endl; // 하나라도 1이면 false

    string bitStr = bit.to_string(); // bitset -> string 형변환
    cout << bitStr << endl;

    cout << bit.to_ulong() << endl; // bitset -> unsigned long 형변환

    int size = bit.size(); // 할당된 비트 수
    cout << size << endl;
}