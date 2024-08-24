        1
       / \
      2   3
     / \   \
    4   5   6
       /
      7
Level 0: Node 1
Level 1: Node 2
Level 2: Node 4
Level 3: Node 7

#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> leftSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            // If it's the first node in the current level, add it to the result
            if (i == 0) {
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

// Definition for a binary tree node.
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

    // First traverse left subtree, then right subtree
    dfs(node->left, depth + 1, result);
    dfs(node->right, depth + 1, result);
}

vector<int> leftSideView(TreeNode* root) {
    vector<int> result;
    dfs(root, 0, result);
    return result;
}
