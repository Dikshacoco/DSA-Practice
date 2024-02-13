// 1) Trie(): Initialize the object of this “TRIE” data structure.

// 2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.

// 3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.

// 4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// 5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    int countEndWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch){
      return (links[ch-'a'] != NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void increaseEnd(){
        countEndWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        countEndWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd(){
        return countEndWith;
    }
    int getPrefix(){
        return countPrefix;
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(string word) {
            Node* node = root;
            int n = word.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                    node->increasePrefix();
                }
                node = node->get(word[i]);
            }
            node->increaseEnd();
        }
        int countWordsEqualTo(string word){
            Node* node = root;
            int n = word.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node = node->get(word[i]);
            }
            return node->getEnd();
        }
        int countWordsStartingWith(string word){
             Node* node = root;
            int n = word.length();
            for(int i = 0; i < n; i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node = node->get(word[i]);
            }
           return node->getPrefix();
        }
        void erase(string& word){
            Node * node = root;
            for (int i = 0; i < word.length(); i++) {
                if (node -> containsKey(word[i])) {
                    node = node -> get(word[i]);
                    node -> reducePrefix();
                } else {
                    return;
                }
            }
            node -> deleteEnd();
        }           
};

int main() {
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}