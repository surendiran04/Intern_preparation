#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    int childCount=0;
    bool containsKey(char &ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char &ch , Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char &ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    void incChild(){
        childCount++;
    }
    int getChildCount(){
        return childCount;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    int CountDistinctSubstrings(string word){
        int cnt=0;
        Node* node;
        int n=word.size();
        for(int i=0; i<n; i++){
            node = root;
            for(int j=i;j<n;j++){
                if(!node->containsKey(word[j]) ){
                    node->put(word[j] , new Node());
                    cnt++;
                }
                node = node->get(word[j]);
            }
            
        }
        return cnt+1;
    }
};

int main(){
     Trie t;
     cout<<"No of Distinct substrings: "<<t.CountDistinctSubstrings("abab")<<endl;//8
     cout<<"No of Distinct substrings: "<<t.CountDistinctSubstrings("abcd");//11

    return 0;
}


