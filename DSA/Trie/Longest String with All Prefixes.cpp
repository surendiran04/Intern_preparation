#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;

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
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if( !node->containsKey(word[i]) ){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkCompletePrefix(string word){ 
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()==0){
                    return false;
                }
            }
            else
               return 0;
        }

        return true;
    }
};
string LongestPrefix(vector<string>& v){ 
//return longest prefix lexigraphically smallest string that matches all the other strings
    Trie t;
    for(string& s:v){
        t.insert(s);
    }
    string longestString="";
    for(auto& s:v){
        if(t.checkCompletePrefix(s)){
            if(s.length()>longestString.length() || s.length()==longestString.length() && s<longestString){
                longestString=s;
            }
        }
    }
    return longestString;
}
int main(){
    vector<string> v={"n","ni","nin","ninj","ninja","ninga","ning"};
    cout<<(LongestPrefix(v))<<endl;

    return 0;
}
