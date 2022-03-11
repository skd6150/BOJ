#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long int getBoundarySum(int y1, int x1, int y2, int x2, vector<vector<long long int>>& sum) {
    return sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1];
}

int main() {
    long long int h, w, res = -1;
    cin >> h >> w;
    vector<vector<long long int>> field(h+1, vector<long long int>(w+1));
    vector<vector<long long int>> sum(h+1, vector<long long int>(w+1));
    for(int i=1; i<=h; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<tmp.length(); j++) {
            field[i][j+1] = tmp[j] - '0';
        }
    }
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            sum[i][j] = field[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for(int i=1; i<=h-2; i++) {
        for(int j=i+1; j<=h-1; j++) {
            res = max(res, getBoundarySum(1,1,i,w,sum)*getBoundarySum(i+1,1,j,w,sum)*getBoundarySum(j+1,1,h,w,sum));
        }
    }
    for(int i=1; i<=w-2; i++) {
        for(int j=i+1; j<=w-1; j++) {
            res = max(res, getBoundarySum(1,1,h,i,sum)*getBoundarySum(1,i+1,h,j,sum)*getBoundarySum(1,j+1,h,w,sum));
        }
    }
    for(int i=1; i<=h-1; i++) {
        for(int j=1; j<=w-1; j++) {
            res = max(res, getBoundarySum(1,1,i,w,sum)*getBoundarySum(i+1,1,h,j,sum)*getBoundarySum(i+1,j+1,h,w,sum)); //up
            res = max(res, getBoundarySum(1,1,i,j,sum)*getBoundarySum(1,j+1,i,w,sum)*getBoundarySum(i+1,1,h,w,sum)); //down
            res = max(res, getBoundarySum(1,1,h,j,sum)*getBoundarySum(1,j+1,i,w,sum)*getBoundarySum(i+1,j+1,h,w,sum)); //left
            res = max(res, getBoundarySum(1,1,i,j,sum)*getBoundarySum(i+1,1,h,j,sum)*getBoundarySum(1,j+1,h,w,sum)); //right
        }
    }
    cout << res << endl;
}