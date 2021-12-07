#include <iostream>
#include <string>
#include <cstring> // strcpy

using namespace std;

int main() {
    string str = "hello world";

    // string -> char* 변환
    char* cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    //cout << cstr << endl;

    // string 길이
    str.size();
    str.length();

    // string resize
    str.resize(5);
    cout << str << endl; // hello
    str.resize(10, '!');
    cout << str << endl; // hello!!!!!

    // modifiers
    str.append("world"); // string append
    str.push_back('!'); // char append
    str.pop_back(); // delete last char

    //operations
    cout << str.find("world") << endl; // find content in string
    cout << str.find("qwerty") << endl; // 없으면 return str.npos

    cout << str.substr(5, 10) << endl; // !!!!!world -> 5~15 부분문자열

    getline(cin, str); // delemeter을 \n로 입력
}