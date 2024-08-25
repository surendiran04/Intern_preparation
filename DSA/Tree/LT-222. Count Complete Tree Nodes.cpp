class Solution {
public:
    int countNodes(TreeNode* root) { //slightly lesser than O(n)
        if (!root) return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (leftHeight == rightHeight) {
            // Left subtree is a perfect binary tree
            return (1 << leftHeight) + countNodes(root->right);  << - left shifts the 1's bit by leftheight digits if leftDigits = 2 then 2^2=4(0100)
        } else {
            // Right subtree is a perfect binary tree one level less
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
    int getHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
};

class Solution { //normal counting
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        return l+r+1;
    }
};
