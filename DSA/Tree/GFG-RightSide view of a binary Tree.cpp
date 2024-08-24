         1
       / \
      2   3
       \   \
        5   4
       /
      6
Level 0: Node 1
Level 1: Node 3
Level 2: Node 4
Level 3: Node 6

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            // Add the last node of each level to the result
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, int depth, vector<int>& result) {
    if (!node) return;

    // If this is the first time we are visiting this depth, add the node's value to the result
    if (depth == result.size()) {
        result.push_back(node->val);
    }

    // First traverse right subtree, then left subtree
    dfs(node->right, depth + 1, result);
    dfs(node->left, depth + 1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    dfs(root, 0, result);
    return result;
}
