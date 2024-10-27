// If we remove the queries[i]th node from tree what will be height of the tree Note:The node is considered to be deleted so it may count for queries[i+1]
// Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
// Output: [2] (The path 1 -> 3 -> 2)
// Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
// Output: [3,2,3,2]
// Explanation: We have the following queries:
// - Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
// - Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
// - Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
// - Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> resultMap;
        unordered_map<TreeNode*, int> heightCache;
        // Run DFS to fill resultMap with maximum heights after each query
        dfs(root, 0, 0, resultMap, heightCache);
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            result[i] = resultMap[queries[i]];
        }
        return result;
    }
private:
    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightCache) {
        if (node == nullptr) {
            return -1;  //Here tree's height calculation is the no of edges
        }
        if (heightCache.count(node)) {
            return heightCache[node];
        }
        int h = 1 + max(height(node->left, heightCache), height(node->right, heightCache));
        heightCache[node] = h;
        return h;
    }
    void dfs(TreeNode* node, int depth, int maxVal, unordered_map<int, int>& resultMap,unordered_map<TreeNode*, int>& heightCache) {
        if (node == nullptr) {
            return;
        }
        resultMap[node->val] = maxVal;
        dfs(node->left, depth + 1,max(maxVal, depth + 1 + height(node->right, heightCache)),resultMap, heightCache); //considering the opp child's height
        dfs(node->right, depth + 1,max(maxVal, depth + 1 + height(node->left, heightCache)), 
        resultMap,heightCache);
    }
};
