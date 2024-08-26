class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
    int maxSum(TreeNode*p,int& maxi){
        if(!p){
            return 0;
        }
        int l=max(0,maxSum(p->left,maxi));
        int r=max(0,maxSum(p->right,maxi));
        maxi=max(maxi,p->val+l+r);
        return max(l,r)+p->val;
    }
};
