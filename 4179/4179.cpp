#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<pair<int, int>> diff = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

bool check(vector<vector<char>> field, int h, int w) {
    for(int i=0; i<h; i++) {
        if(field[i][w-1] == 'J') return true;
    }
    for(int i=0; i<h; i++) {
        if(field[i][0] == 'J') return true;
    }
    for(int i=0; i<w; i++) {
        if(field[h-1][i] == 'J') return true;
    }
    for(int i=0; i<w; i++) {
        if(field[0][i] == 'J') return true;
    }
    return false;
}

void move(vector<vector<char>>& field, queue<pair<int, int>>& player, int h, int w) {
    queue<pair<int, int>> tmp;
    while(!player.empty()) {
        pair<int, int> cur = player.front();
        player.pop();
        for(pair<int, int> d: diff) {
            pair<int, int> next = make_pair(cur.first + d.first, cur.second + d.second);
            if(next.first < 0 || next.first >= h) continue;
            if(next.second < 0 || next.second >= w) continue;
            if(field[next.first][next.second] != '.') continue;
            field[next.first][next.second] = 'J';
            tmp.push(next);
        }
    }
    player = tmp;
}

void expand(vector<vector<char>>& field, queue<pair<int, int>>& fire, int h, int w) {
    queue<pair<int, int>> tmp;
    while(!fire.empty()) {
        pair<int, int> cur = fire.front();
        fire.pop();
        for(pair<int, int> d: diff) {
            pair<int, int> next = make_pair(cur.first + d.first, cur.second + d.second);
            if(next.first < 0 || next.first >= h) continue;
            if(next.second < 0 || next.second >= w) continue;
            if(field[next.first][next.second] == '#') continue;
            if(field[next.first][next.second] == 'F') continue;
            field[next.first][next.second] = 'F';
            tmp.push(next);
        }
    }
    fire = tmp;
}

int main() {
    int w, h, t = 1;
    cin >> h >> w;
    vector<vector<char>> field(h, vector<char>(w));
    queue<pair<int, int>> fire, player;
    for(int i=0; i<h; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<w; j++) {
            field[i][j] = tmp[j];
            if(tmp[j] == 'F') fire.push(make_pair(i, j));
            if(tmp[j] == 'J') player.push(make_pair(i, j));
        }
    }

    while(true) {
        if(check(field, h, w)) {
            cout << t << endl;
            return 0;
        }
        t++;
        expand(field, fire, h, w);
        move(field, player, h, w);
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cout << field[i][j];
            }
            cout << endl;
        }
        if(player.empty()) break;
    }
    cout << "IMPOSSIBLE " << endl;
}
