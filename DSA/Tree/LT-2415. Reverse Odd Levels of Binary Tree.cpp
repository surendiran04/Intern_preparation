class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        int level=0;
        TreeNode* p=root;
        q.push(p);
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> v;
            for(int i=0;i<n;i++){
                p=q.front();
                q.pop();
                v.push_back(p);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            if(level & 1){  //the current levels values are in the vector v so we are just swapping the values of nodes
                int m=v.size();
                for(int i=0;i<m/2;i++){
                    swap(v[i]->val,v[m-i-1]->val);
                }
            }
            level++;
            v.clear();
        }
        return root;    
    }
};
