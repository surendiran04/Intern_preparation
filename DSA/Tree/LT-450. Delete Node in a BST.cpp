class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }else if(key>root->val){
                root->right=deleteNode(root->right,key);
            }
            else{
                if(!root->left && !root->right){
                    return nullptr;
                }
                if(!root->left || !root->right){
                    return root->left?root->left:root->right;
                }
                root->val=successor(root->right);  //here we can delete the inorder predecessor as well on root->left
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
    int successor(TreeNode* root){
        while(root && root->left){
            root=root->left;
        }
        return root->val;
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }else if(key>root->val){
                root->right=deleteNode(root->right,key);
            }
            else{
                if(!root->left && !root->right){
                    return nullptr;
                }
                if(!root->left || !root->right){
                    return root->left?root->left:root->right;
                }
                if(height(root->left)<height(root->right)){
                    root->val=successor(root->right);
                    root->right=deleteNode(root->right,root->val);
                }else{
                    root->val=predecessor(root->left);
                    root->left=deleteNode(root->left,root->val);
                }
                
            }
        }
        return root;
    }
    int successor(TreeNode* root){
        while(root && root->left){
            root=root->left;
        }
        return root->val;
    }
    int predecessor(TreeNode* root){
        while(root && root->right){
            root=root->right;
        }
        return root->val;
    }
    int height(TreeNode* root){
        if(!root){
            return -1;
        }
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
};
