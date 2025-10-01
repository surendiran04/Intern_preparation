class Solution { //O(h) Time and O(h) Space
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

Node* LCA(Node* root, Node* n1, Node* n2) { //O(h) Time and O(1) Space

    while (root != nullptr) {
      
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1->data && root->data > n2->data)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1->data && root->data < n2->data)
            root = root->right;
        
        // Else Ancestor is found
        else
            break;
    }

    return root;
}
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
