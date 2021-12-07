#include <iostream>
#include <set>

using namespace std;

int main() {
    //set: 이진균형트리, 중복X
    set<int> lSet; //내림차순
    set<int, greater<int>> gSet; //오름차순
    multiset<int> multiSet; // 중복가능

    lSet.insert(1);
    lSet.insert(2);
    lSet.insert(3);
    lSet.insert(5);

    pair<set<int>::iterator, bool> res = lSet.insert(4);
    // cout << res.second << endl; // 성공시 res.second true, 실패(중복 등)시 res.second false

    lSet.erase(2); // 삭제
    lSet.insert(2);

    // cout << lSet[0] << endl; // set은 임의접근이 불가능

    for(auto it: lSet) { // 중위순회를 통해 작은 원소부터 출력
        cout << it << endl; //1 2 3
    }

    cout << *lSet.lower_bound(3) << endl; // 3출력, 3이 처음 나오는 구간 반복자
    cout << *lSet.upper_bound(3) << endl; // 4출력, 3이 끝난 다음 구간 반복자

    // 4가 있으면 해당 iterator반환, 없으면 lSet.end() 반환
    if(lSet.find(4) == lSet.end()) {
        cout << "N" << endl;
    }
    else {
        cout << "Y" << endl;
    }
}