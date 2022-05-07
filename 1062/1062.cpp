#include <iostream>
#include <vector>
#include <string>
using namespace std;

int result = 0;

int ascii(char c) {
   return c - 'a';
}

void find(vector<bool> mask, int idx, int cur, int limit, vector<vector<char>>& words) {
   if(cur == limit) {
      int res = 0;
      for(vector<char> word: words) {
         bool flag = true;
         for(char c: word) {
            if(mask[ascii(c)]) continue;
            flag = false;
            break;
         }
         if(flag) res++;
      }

      // cout << res << " ";
      // for(int i=0; i<26; i++) {
      //    if(mask[i]) cout << (char)(i + 'a');
      // }
      // cout << endl;

      result = max(result, res);
      return;
   }
   if(idx == 26) return;
   find(mask, idx+1, cur, limit, words);
   if(!mask[idx]) {
      mask[idx] = true;
      find(mask, idx+1, cur+1, limit, words);
   }
}

int main() {
   int n, k;
   cin >> n >> k;
   vector<bool> mask(26, false);
   vector<vector<char>> words(n);
   mask[ascii('a')] = mask[ascii('n')] = mask[ascii('t')] = mask[ascii('i')] = mask[ascii('c')] = true;
   for(int i=0; i<n; i++) {
      string tmp;
      vector<bool> check(26);
      cin >> tmp;
      for(char c: tmp) {
         if(check[ascii(c)]) continue;
         words[i].push_back(c);
         check[ascii(c)] = true;
      }
   }
   if(k < 5) {
      cout << 0 << endl;
      return 0;
   }
   find(mask, 0, 5, k, words);
   cout << result << endl;
}