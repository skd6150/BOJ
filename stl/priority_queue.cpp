#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int main() {
    priority_queue<int, vector<int>, less<int>> pq; // max heap
    // priority_queue<int, vector<int>, greater<int>> pq; // min heap

    // priority_queue에 pair, vector 등을 넣는 경우 템플릿 매개변수로 자료형, 자료형이 담길 자료형(vector 등), 비교 구조체 필요
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pairPq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << pq.size() << endl;

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}