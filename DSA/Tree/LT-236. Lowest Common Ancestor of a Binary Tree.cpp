class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        vector<TreeNode*>pathP,pathQ;
        getPath(root,pathP,p);
        getPath(root,pathQ,q); //getting the path from the root to that node
        TreeNode*ans;
        for(int i=0;i<pathQ.size() && i<pathP.size();i++){ //the node which common between the node is the and among the equal nodes retuning the nearest one
            if(pathQ[i]==pathP[i]){
                ans=pathP[i];
            }
        }
        return ans;
    }
    bool getPath(TreeNode* p, vector<TreeNode*>& v, TreeNode* x) {
        if (!p)
            return false;
        v.push_back(p);
        if (p == x)
            return true;
        if (getPath(p->left, v, x) || getPath(p->right, v, x))
            return true;
        v.pop_back();
        return false;
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { //If l and r not nullptr means some node(root) has p,q as its child notes
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
