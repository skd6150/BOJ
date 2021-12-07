#include <iostream>
#include <map>

using namespace std;

int main() {
    // map: key, value로 이루어진 트리, 레드블랙트리(검색, 삽입, 삭제 O(logn))
    map<string, int, less<string>> m; // 키 중복 불가
    multimap<string, int, less<string>> multiMap; // 키 중복 가능

    //insert
    m.insert({"key1", 30});
    m.insert({"key2", 50});

    //search
    if(m.find("key") == m.end()) {
        cout << "not found" << endl;
    }
    else {
        cout << "found" << endl;
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }

    //delete
    m.erase("key1");
    m.erase(m.begin());
}