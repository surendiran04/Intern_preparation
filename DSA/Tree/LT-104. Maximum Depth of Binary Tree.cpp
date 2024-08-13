class Solution {
public:
    int maxDepth(TreeNode* root) {
       int l,r;
       if(root==nullptr){
         return 0;
       }
       l=maxDepth(root->left);
       r=maxDepth(root->right);
       if(l>r){
         return l+1;
       }
       else{
         return r+1;
       }
    }
};
