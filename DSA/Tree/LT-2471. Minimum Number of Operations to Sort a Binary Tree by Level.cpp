class Solution {
public:
    int minimumOperations(TreeNode* root) {
         if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        vector<pair<int,int>> v;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                root = q.front();
                q.pop();
                v.push_back({root->val,i});
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                int k=v[i].second;
                if(k==i) continue;
                else{
                    cnt++;
                    swap(v[i],v[k]);
                    i--;
                }
            }
            v.clear();
        }
        return cnt;
    }
};
