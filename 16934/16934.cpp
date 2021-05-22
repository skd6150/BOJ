#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int toNum(char ch) {
	return ch - 'a';
}

struct trie {
	bool terminal = false;
	int tag = 1;
	trie* children[26];
	trie() {
		memset(children, 0, sizeof(children));
	}
	
	void insert(char* str) {
		if(*str == 0) {
			if(terminal) tag++;
			terminal = true;
		}
		else {
			int next = toNum(*str);
			if(children[next] == NULL) {
				children[next] = new trie();
			}
			children[next]->insert(str+1);
		}
	}
	
	trie* find(char* str) {
		if(*str == 0) return this;
		int next = toNum(*str);
		if(children[next] == NULL) return NULL;
		return children[next]->find(str+1);
	}
};


int main() {
	trie T, nicknames;
	int names;
	
	scanf("%d", &names);
	for(int i=0; i<names; i++) {
		char name[10];
		bool flag = false;
		scanf("%s", name);
		
		trie* test = T.find(name);
		if(test != NULL) {
			if(test->terminal) {
				//cout << name << test->tag+1 << endl;
				printf("%s%d\\nn", name, test->tag+1);
			}
			else {
				//cout << name << endl;
				printf("%s", name);
			}
			T.insert(name);
			continue;
		}
		
		for(int i=1; i<=10 || name[i] != '\0'; i++) {
			char tmp[10];
			for(int j=0; j<i; j++) {
				tmp[j] = name[j];
				tmp[j+1] = '\0';
			}
			
			trie* res = T.find(tmp);
			if(res == NULL) {
				//cout << tmp << endl;
				printf("%s", tmp);
				break;
			}
		}
		T.insert(name);
	}
}










