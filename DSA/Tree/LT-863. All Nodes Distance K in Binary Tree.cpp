class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj) {
        if (!root) return;
        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right, adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        buildGraph(root, adj);

        unordered_map<TreeNode*, bool> vis;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        vis[target] = true;

        vector<int> ans;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) ans.push_back(node->val);

            for (auto neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push({neigh, dist + 1});
                }
            }
        }

        return ans;
    }
};
