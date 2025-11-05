class Solution {
public:
    string lcaToStart,lcaToEnd;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=LCA(root,startValue,destValue);
        string pathString="";
        dfs(lca,pathString,startValue,destValue);

        for(char& ch:lcaToStart){
            ch='U';
        }
        return lcaToStart+lcaToEnd;

    }
    void dfs(TreeNode* root,string& path,int p,int q){
        if(!root){
            return;
        }
        if(root->val==p){
            lcaToStart=path;
        }
        if(root->val==q){
            lcaToEnd=path;
        }
        path+='L';
        dfs(root->left,path,p,q);
        path.pop_back();
        path+='R';
        dfs(root->right,path,p,q);
        path.pop_back();
    }
    TreeNode* LCA(TreeNode* root,int p,int q){
        if(!root || root->val==p || root->val==q){
            return root;
        }
        TreeNode *l=LCA(root->left,p,q);
        TreeNode *r=LCA(root->right,p,q);
        if(!l){
            return r;
        }else if(!r){
            return l;
        }
        return root;
    }
};
