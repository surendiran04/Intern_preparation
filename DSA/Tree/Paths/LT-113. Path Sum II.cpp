class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> t;
        helper(root,targetSum,ans,t);
        return ans;
    }
    void helper(TreeNode *root,int k,vector<vector<int>>& ans,vector<int> t){
        if(!root){
            return;
        }
        t.push_back(root->val);
        if(!root->left && !root->right && root->val==k){
            ans.push_back(t);
        }
        helper(root->left,k-root->val,ans,t);
        helper(root->right,k-root->val,ans,t);
    }
};
