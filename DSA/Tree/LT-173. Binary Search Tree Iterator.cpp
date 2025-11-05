class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
       TreeNode *t=st.top();st.pop();
       pushAll(t->right);
       return t->val; 
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
};
