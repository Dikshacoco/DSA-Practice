#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag = true;
    }
};


class Trie
{
  private:
  Node* root;

  public:

  Trie()
  {
    root = new Node();
  }

  void insert(string &word)
  {
    Node* node = root;
    for(int i = 0;i<word.size();i++)
    {
      if(!node->containsKey(word[i]))
      {
         node->put(word[i],new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  

  bool checkPrefixExist(string &word)
  {
    Node* node = root;
    for(int i = 0;i<word.size();i++)
    {
      if(node->containsKey(word[i]))
      {
        node = node->get(word[i]);
        if(node->isEnd() == false) return false;
      }
      else{
        return false;
      }
    }
    return true;
  }

};




string completeString(int n, vector<string> &a){
    // Write your code here.

Trie trie;
string longest = "";

for(auto &it:a)
{
  trie.insert(it);
}

for(auto &it:a)
{
  if(trie.checkPrefixExist(it))
  {
    if(it.length() > longest.length())
    {
      longest = it;
    }
    else if(it.length() == longest.length() && it < longest)
    {
      longest = it;
    }
  }
}

if(longest == "")
{
  return "None";
}
return longest;
}

int main() {
    vector<string> a;
    a.push_back("n");
    a.push_back("ni");
    a.push_back("nin");
    a.push_back("ninj");
    a.push_back("ninja");
    a.push_back("ninga");

    cout<<completeString(a.size(), a);
}
