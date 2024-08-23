class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) { //diameter can be the longest path from any node 
       int res=0;
       height(root,res); //diameter = height of the left tree + height of the right sub tree , we need the max in it not from the root (height of the tree)
       return res;
    }
    int height(TreeNode* root,int &res){
        int l,r;
       if(root==nullptr){
         return 0;
       }
       l=height(root->left,res);
       r=height(root->right,res);
       res=max(res,l+r);
       if(l>r){
         return l+1;
       }
       else{
         return r+1;
       }
    }
};
