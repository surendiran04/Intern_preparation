class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        getNodes(root,v);
        return v[k-1];
    }
    void getNodes(TreeNode* p,vector<int> &v){
        if(p){
            getNodes(p->left,v);
            v.push_back(p->val);
            getNodes(p->right,v);
        }
    }
};
class Solution {
public:
    int i=0,ans=0;
    int kthSmallest(TreeNode* root, int k) {
        getNode(root,k);
        return ans;
    }
    void getNode(TreeNode* p,int k){
        if(p){
            getNode(p->left,k);
            i++;
            if(i==k){
                ans=p->val;
                return;
            } 
            getNode(p->right,k);
        }
    }
};
