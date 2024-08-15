class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int m = q.size();
            vector<int> ans;
            for (int i = 0; i < m; i++) {
                root = q.front();
                q.pop();
                ans.push_back(root->val);
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            v.push_back(ans);
            ans.clear();
        }
        return v;
    }
};
