#include <iostream>
#include <vector>
#include <string>
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(arr, tree, node*2, start, (start+end)/2) * init(arr, tree, node*2+1, (start+end)/2+1, end);
    }
}

int sum(vector<int>& tree, int node, int start, int end, int left, int right) {
    if(right < start || left > end) return 1;
    if(left <= start && right >= end) return tree[node];
    return sum(tree, node*2, start, (start+end)/2, left, right) * sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int update(vector<int>& tree, int node, int start, int end, int index, int newValue) {
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = newValue;
    int leftUpdate = update(tree, node*2, start, (start+end)/2, index, newValue);
    int rightUpdate = update(tree, node*2+1, (start+end)/2+1, end, index, newValue);
    return tree[node] = leftUpdate * rightUpdate;
}

int hashNumber(int num) {
    if(num == 0) return 0;
    else return num > 0 ? 1 : -1;
}

int main() {
    while(true) {
        int arrSize, querySize;
        string result = "";
        vector<int> arr;
        vector<int> tree = vector<int>(arrSize*4, 0);
        cin >> arrSize >> querySize;
        if(cin.eof()) break;
        tree = vector<int>(arrSize*4, 0);
        for(int i=0; i<arrSize; i++) {
            int tmp;
            cin >> tmp;
            arr.push_back(hashNumber(tmp));
        }
        init(arr, tree, 1, 0, arrSize-1);
        for(int i=0; i<querySize; i++) {
            char query;
            int arg1, arg2;
            cin >> query >> arg1 >> arg2;
            if(query == 'C') {
                int index = arg1 - 1;
                int newValue = hashNumber(arg2);
                update(tree, 1, 0, arrSize-1, index, newValue);
            }
            else {
                int left = arg1 - 1;
                int right = arg2 - 1;
                int sumValue = sum(tree, 1, 0, arrSize-1, left, right);
                if(sumValue == 0) result += "0";
                else result += (sumValue > 0) ? "+" : "-";
            }
        }
        cout << result << endl;
    }
}