//Check if 2 integers are counsins in a tree
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {  //we also use a map to store the depth and it's values as a vector if value == x or y
        queue<TreeNode*> q;
        q.push(root);
        bool found = false;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                TreeNode* p = q.front();
                q.pop();
                if ( (p->left && p->left->val == x) || ( p->right && p->right->val == x )) {
                    found = true;
                } else {
                    if (p->left)
                        q.push(p->left);
                    if (p->right)
                        q.push(p->right);
                }
            }
            if (found) {
                break;
            }
        }
        while (!q.empty()) {
            int z = q.front()->val;
            q.pop();
            if (z == y) {
                return true;
            }
        }
        return false;
    }
};
