 class BSTIterator {
public:
    stack<TreeNode*> st;
    bool isReverse=true;
    BSTIterator(TreeNode* root,bool flag) { //We also do it using Inorder by storing it
        isReverse=flag;
        pushAll(root);
        
    }
    int next() {
       TreeNode *t=st.top();st.pop();
       if(isReverse){ //before
          pushAll(t->left);
       }else{
        pushAll(t->right);
       }
       return t->val; 
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(isReverse){
                node=node->right;
            }else{
                node=node->left;
            } 
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
          if(!root){
            return false;
          }
          BSTIterator l(root,false);
          BSTIterator r(root,true);
          int i=l.next(),j=r.next();
          while(i<j){
            if(i+j==k){
                return true;
            }else if(i+j<k){
                i=l.next();
            }else{
                j=r.next();
            }
          }
          return false;
    }
};
