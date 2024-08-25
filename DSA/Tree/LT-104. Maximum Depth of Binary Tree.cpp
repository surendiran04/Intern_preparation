class Solution {
public:
    int maxDepth(TreeNode* root) {
       int l,r;
       if(root==nullptr){
         return 0;
       }
       l=maxDepth(root->left);
       r=maxDepth(root->right);
       if(l>r){
         return l+1;
       }
       else{
         return r+1;
       }
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        int ans=0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            depth++;
            ans=max(ans,depth);
        }
        return ans;
    }
};
