class Solution {
public:
    int count=0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        helper(root,targetSum);
        if(root->left){
            pathSum(root->left,targetSum);
        }
        if(root->right){
            pathSum(root->right,targetSum);
        }
        return count;
    }
    void helper(TreeNode* root,long long k){
        if(!root){
            return;
        }
        if(k==root->val){
            count++;
        }
        helper(root->left,k-root->val);
        helper(root->right,k-root->val);
    }
};
