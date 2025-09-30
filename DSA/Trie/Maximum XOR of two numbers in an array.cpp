#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];
    bool containsKey(int ch){
        return links[ch] != NULL;
    }

    void put(int ch , Node* node){
        links[ch] = node;
    }

    Node* get(int ch){
        return links[ch];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
         Node* node=root;
        for(int i=31;i>=0;i--){
                 int bit = (num>>i) & 1;
                if(!node->containsKey(bit)){ 
                    node->put(bit,new Node());
                }
                node=node->get(bit);
        }
    }

    int getMax(int num){
        int maxNum=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1; //taking ith bit
                if(node->containsKey(1-bit)){ //picking out the max one
                    maxNum=maxNum | (1<<i);
                    node=node->get(1-bit);
                }else{
                    node = node->get(bit); //our maximum not available
                }
        }
        return maxNum;
    }
};
int maxEXor(vector<int>& a,vector<int>& b){
    Trie t;
    for(int& n:a){
        t.insert(n);
    }
    int maxEXor=0;
    for(int& n:b){
        maxEXor=max(maxEXor,t.getMax(n));
    }
    return maxEXor;
}
int main(){
    vector<int> a={2,5};
    vector<int> b={7,0,3,25};
     cout<<"Maximum EXor value: "<<maxEXor(a,b)<<endl;//28

    return 0;
}


