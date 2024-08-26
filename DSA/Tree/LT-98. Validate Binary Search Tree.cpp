class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
    bool check(TreeNode* root,long min,long max){
        if(!root) return true;
        if( root->val <= min ||  root->val >= max){
            return false;
        }else{
            return check(root->left,min,root->val) && check(root->right,root->val,max); //for the left subtree, root->val is the max val 
                                                                                        //for the root->right subtree, root->val is the min val
        }
    }
};
