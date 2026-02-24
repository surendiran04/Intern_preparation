class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<string> bin;
        string s;
        allPaths(root,bin,s);
        int sum=binToInt(bin);
        return sum;
    }
    int binToInt(vector<string>& bin){
        int sum=0;
         for(string s:bin){
            int num=0,div=0;
            for(int i=s.length()-1;i>=0;i--){
                if(s[i]=='1'){
                    num+=pow(2,div);
                }
                div++;
            }
            cout<<s<<":"<<num<<endl;
            sum+=num;
         }
         return sum;
    }
    void allPaths(TreeNode* p,vector<string>& bin,string s){
        if(!p){
           return;
        }
        s.push_back((p->val+'0'));
        if(!p->left && !p->right){
            bin.push_back(s);
        }
        allPaths(p->left,bin,s);
        allPaths(p->right,bin,s);
    }
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) { //1 pass
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr = curr * 2 + node->val; // append this bit

        if (!node->left && !node->right) // leaf
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};
