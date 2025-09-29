#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    void put(char ch,Node* n){
        links[ch-'a']=n;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
          Node* root;
    public:
      Trie(){
          root=new Node();
      }
      void insert(string& s){
          Node* n=root;
          for(char ch:s){
              if(!n->containsKey(ch)){
                  n->put(ch,new Node());
              }
              n=n->get(ch);
          }
          n->setEnd(); //marking the letter ends
      }
      bool search(string& s){
          Node* n=root;
          for(char ch:s){
              if(!n->containsKey(ch)){
                  return false;
              }
              n=n->get(ch);
          }
          return n->isEnd(); //The word is completely available in the tree
      }
      bool startsWith(string& s){
          Node* n=root;
          for(char& ch:s){
              if(!n->containsKey(ch)){
                  return false;
              }
              n=n->get(ch);
          }
          return true;  // the word is prefix or complete available word in the trie
      }
};

int main() {
    Trie t;
    string a="apple";
    string b="apps";
    string c="app";
    string d="appx";
    t.insert(a);
    cout<<t.search(a)<<" "<<t.search(b)<<" "<<t.startsWith(c)<<" "<<t.startsWith(d)<<endl;
    cout<<t.search(c);
    return 0;
}
