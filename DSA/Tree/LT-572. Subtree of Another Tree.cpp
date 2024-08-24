class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
       if(check(root,subRoot)){
        return true;
       }

       return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool check(TreeNode* root,TreeNode* subRoot){
         if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        if(root->val==subRoot->val){
            return check(root->left,subRoot->left) && check(root->right,subRoot->right);
        }
        return false;
    }
};
