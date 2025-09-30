#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char &ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char &ch , Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char &ch){
        return links[ch - 'a'];
    }

    void increasePrefix(){
        cntPrefix++;
    }
    
    void increaseEnd(){
        cntEndsWith++;
    }

    void decreasePrefix(){
        cntPrefix--;
    }
    
    void decreaseEnd(){
        cntEndsWith--;
    }

    int getEndCount(){
        return cntEndsWith;
    }

    int getPrefixCount(){
        return cntPrefix;
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
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){ //Exact word needs to be there
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) ){
                node = node->get(word[i]);
            }
            else    return 0;
        }

        return node->getEndCount();
    }

    int countWordsStartingWith(string word){ //Just the count of prefix 
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if( node->containsKey(word[i]) ){
                node = node->get(word[i]);
            }
            else    return 0;
        }

        return node->getPrefixCount();
    }

    bool erase(string word){
        if( countWordsEqualTo(word) == 0 )  return false;

        Node* node = root;
        for(int i=0; i<word.size(); i++){
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
        return true;
    }
};
int main(){
    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
    t.insert("apps");
    t.insert("apxl");
    t.insert("bgmi");

    cout<<"Count of apple "<<t.countWordsEqualTo("apple")<<endl;
    cout<<"Count of apps "<<t.countWordsEqualTo("apps")<<endl;
    cout<<"Count of app "<<t.countWordsEqualTo("app")<<endl;

    cout<<"Count of starting with app "<<t.countWordsStartingWith("app")<<endl;
    cout<<"Count of starting with pps "<<t.countWordsStartingWith("pps")<<endl;

    cout<<t.erase("apple")<<endl;
    cout<<t.erase("appls")<<endl;

    cout<<"Count of apple "<<t.countWordsEqualTo("apple")<<endl;
    cout<<"Count of starting with app "<<t.countWordsStartingWith("app")<<endl;

    return 0;
}
