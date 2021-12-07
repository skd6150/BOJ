#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> deque1; // empty deque
    deque<int> deque2(5); // {0, 0, 0, 0, 0}
    deque<int> deque2(3, 5); // {5, 5, 5}

    deque1.push_back(1);
    deque1.push_front(2);
    deque1.pop_back();
    deque1.pop_front();
}