Input: root = [3,9,20,null,null,15,7]
Output: 2
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
class Solution {
public:
    int minDepth(TreeNode* root) {
       if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1; 
        while (!q.empty()) {
            int size = q.size();
    
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node->left && !node->right) {
                    return depth;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ++depth;
        }
        return depth;
    }
};  
class Solution {
public:
    int minDepth(TreeNode* root) {
       if(!root)
          return 0;
        if(!root->left){
            return 1+minDepth(root->right);
        }
        if(!root->right){
            return 1+minDepth(root->left);
        }  
        return 1+min(minDepth(root->left),minDepth(root->right)); 
    }
};
