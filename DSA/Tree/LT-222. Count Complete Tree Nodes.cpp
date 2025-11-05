class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh){
            return (1<<lh)-1; //2^h-1 is the max no of nodes if the tree is perfect tree
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftheight(TreeNode* r){ //here it claculates the no of nodes in log(h) times
        int cnt=0;
        while(r){
            cnt++;
            r=r->left;
        }
        return cnt;
    }
    int rightheight(TreeNode* r){
        int cnt=0;
        while(r){
            cnt++;
            r=r->right;
        }
        return cnt;
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
