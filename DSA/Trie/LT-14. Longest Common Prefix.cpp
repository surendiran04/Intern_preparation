// Input: strs = ["flower","flow","flight"]
// Output: "fl"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { //O(n^2)
        if(strs.empty()) 
            return "";
         string prefix=strs[0];
         for(string s:strs){
            while(s.find(prefix)!=0)
                prefix=prefix.substr(0,prefix.length()-1);
         }
         return prefix;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
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

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]) ){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
            node->incChild();
        }
        node->setEnd();
    }

     string checkCompletePrefix(string word,int n){ 
        Node* node = root;
        string ans="";
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                int x=node->getChildCount();
                if(x==n){
                    ans+=word[i];
                }
                if(node->isEnd() || x<n){
                    return ans;
                }  
            }
            else
               return ans;
        }

        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
    int n=v.size();
    Trie t;
    for(string& s:v){
        t.insert(s);
    }
    return t.checkCompletePrefix(v[0],n);
    }
};
