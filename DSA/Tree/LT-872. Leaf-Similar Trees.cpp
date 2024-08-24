class Solution {
public:
    bool leafSimilar(TreeNode* p, TreeNode* q) {
        vector<int> leavesP,leavesQ;
        Leaves(p,leavesP);
        Leaves(q,leavesQ);
        return leavesP==leavesQ;
    }
    void Leaves(TreeNode* p,vector<int>&v){
        if(!p){
            return;
        }
        if(!p->left && !p->right)
           v.push_back(p->val);
        Leaves(p->left,v);
        Leaves(p->right,v);
    }
};
