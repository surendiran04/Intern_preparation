// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
class Solution {
public:
    int sumNumbers(TreeNode* root) {
         return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int pathSum) {
        if (!node)
            return 0;
        
        pathSum = pathSum * 10 + node->val;
        
        if (!node->left && !node->right)
            return pathSum;
        
        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }
};
