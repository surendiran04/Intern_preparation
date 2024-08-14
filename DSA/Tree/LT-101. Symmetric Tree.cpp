class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
    bool check(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        if(p->val==q->val){
            return check(p->left,q->right) && check(p->right,q->left);
        }
        return false;
    }
};
