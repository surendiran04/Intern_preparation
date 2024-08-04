class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> st;
        while(!st.empty() || root!=nullptr){
            while(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            root=root->right;
        }
        return ans;

    }
};
class Solution {  //recursive soln
public:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == NULL) return;
        inorderHelper(node->left, result);  // Traverse left subtree
        result.push_back(node->val); 
        inorderHelper(node->right, result); // Traverse right subtree
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};
