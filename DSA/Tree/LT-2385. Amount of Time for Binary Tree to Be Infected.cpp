class Solution {
public:
      void buildGraph(TreeNode* root, unordered_map<int, vector<TreeNode*>>& adj) {
        if (!root) return;
        if (root->left) {
            adj[root->val].push_back(root->left);
            adj[root->left->val].push_back(root);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right);
            adj[root->right->val].push_back(root);
            buildGraph(root->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<TreeNode*>> map;
        buildGraph(root,map);
        queue<pair<int,int>> q;
        q.push({start,0});
        unordered_map<int,bool> vis;
        vis[start]=true;
        int minutes=0;
        while(!q.empty()){
            int n=q.size();
            bool infected=false;
            for(int i=0;i<n;i++){
                auto [node,time]=q.front();
                q.pop();
                for(auto adj:map[node]){
                    if(vis.find(adj->val)==vis.end()){
                        vis[adj->val]=true;
                        q.push({adj->val,time+1});
                        infected=true;
                    }
                }
            }
            if(infected){
                 minutes++;
            }
        }
        return minutes;
    }
};
