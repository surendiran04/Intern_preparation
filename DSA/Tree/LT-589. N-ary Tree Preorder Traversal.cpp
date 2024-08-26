class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        stack<Node*> st;
        vector<int> v;
        st.push(root);
        while(!st.empty()){
            Node* t=st.top();
            st.pop();
            v.push_back(t->val);
            for(int i=t->children.size()-1;i>=0;i--){
                st.push(t->children[i]);
            }
        }
        return v;
    }
};
class Solution { //recursive soln
public:

    void pre(Node *root , vector<int>&v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        for(int i=0;i<(root->children).size();i++){
            pre((root->children)[i],v);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int>v;
        pre(root,v);
        return v;
    }
};
