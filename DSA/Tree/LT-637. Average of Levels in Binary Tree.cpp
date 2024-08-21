// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
         if (root == nullptr) {
            return {};
        }
        vector<double> v;
        queue<TreeNode*> q;
        q.push(root);
        long ans;
        while (!q.empty()) {
            int m = q.size();
              ans=0;
            for (int i = 0; i < m; i++) {
                root = q.front();
                q.pop();
                ans+=root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            v.push_back((double)ans/m);
        }
        return v;
    }
};
