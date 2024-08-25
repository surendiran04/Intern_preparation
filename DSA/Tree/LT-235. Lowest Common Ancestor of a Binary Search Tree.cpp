class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { //for binary search tree
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val){
            return   lowestCommonAncestor(root->right,p,q);
        }
        else 
           return root;
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* l =lowestCommonAncestor(root->left,p,q);
        TreeNode* r =lowestCommonAncestor(root->right,p,q);
        if(l==nullptr){
            return r;
        }
        else if(r==nullptr){
            return l;
        }else{
            return root;
        }
    }
};
