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
 public:
    Node* root;
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
        n->setEnd();
     }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { //O(n^2+m*k)
        Trie tr;
        for(auto s:wordDict){ //O(m*k)
            tr.insert(s);
        }
        int n=s.length();
        vector<int> dp(n,0);
        int m=s.length();
        for(int i=0;i<m;i++){  //O(n^2)
            if(i-1==-1 || dp[i-1]){
                Node* t =tr.root;
                for(int j=i;j<n;j++){
                    if(!t->containsKey(s[j])){
                        break;
                    }
                    t=t->get(s[j]);
                    if(t->isEnd()){
                        dp[j]=1;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
