//Implementing insertion, search, and startWith operations in a trie or prefix-tree
// Type 1: To insert a string “word” in Trie.                           

// Type 2: To check if the string “word” is present in Trie or not.

// Type 3: To check if there is any string in the Trie that starts with the given prefix string “word”.    

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1

struct Node{
	Node *link[26];
	bool flag = false;

	bool containsKey(char ch){
		return (link[ch - 'a'] != NULL);
	}

	void put(char ch, Node* node){
		link[ch-'a'] = node;
	}

	Node* get(char ch){
		return link[ch-'a'];
	}

	bool isEnd(){
		return flag;
	}

	void setEnd() {
		flag = true;
	}

};

class Trie {
	private:
		Node* root;
	public:
		Trie(){
			root = new Node();
		}
		void insert(string word){
			Node* node = root;
			int n = word.length();
			for(int index = 0; index < n; index++){
				if(!node->containsKey(word[index]))
					node->put(word[index], new Node());
				node = node->get(word[index]);
			}
			node->setEnd();
		}
		bool search(string word){
			Node* node = root;
			int n = word.length();
			for(int index = 0; index < n; index++){
				if(!node->containsKey(word[index]))
					return false;
				node = node->get(word[index]);
			}
			return node->isEnd();
		}
		bool startsWith(string word){
			Node* node = root;
			int n = word.length();
			for(int index = 0; index < n; index++){
				if(!node->containsKey(word[index]))
					return false;
				node = node->get(word[index]);
			}
			return true;
		}
};
int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"apple", "app", "abc", "apple", "aape"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}