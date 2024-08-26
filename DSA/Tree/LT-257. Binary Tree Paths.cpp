class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<string> v;
        string x;
        getPath(root, v, x);
        return v;
    }
    void getPath(TreeNode* p, vector<string>& v, string x) {
        if (!p) {
            return;
        }
        x += to_string(p->val);
        if (!p->left && !p->right) {
            v.push_back(x);
        }
        x += "->";
        getPath(p->left, v, x);
        getPath(p->right, v, x);
    }
};
