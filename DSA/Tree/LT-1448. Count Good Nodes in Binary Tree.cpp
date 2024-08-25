class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
    int dfs(TreeNode* p,int maxval) {
        if (!p) {
            return 0;
        }
        int count=0;
        if(p->val>=maxval){
            count=1;
            maxval=p->val;
        }
        count+=dfs(p->left,maxval);
        count+=dfs(p->right,maxval);
        return count;
    }
};
