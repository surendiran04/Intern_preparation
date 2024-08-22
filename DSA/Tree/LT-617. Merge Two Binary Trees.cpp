class Solution {
public:
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) { //creating a new tree
          if(!p || !q){
             return (p!=nullptr)?p:q;
          }
          TreeNode* root = new TreeNode(p->val+q->val);
          root->left=mergeTrees(p->left,q->left);
          root->right=mergeTrees(p->right,q->right);
          return root;
    }
};
class Solution { //without creating a new tree - uses less space
public:
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
          if(!p || !q){
             return (p!=nullptr)?p:q;
          }
          p->val+=q->val;
          p->left=mergeTrees(p->left,q->left);
          p->right=mergeTrees(p->right,q->right);
          return p;
    }
};
