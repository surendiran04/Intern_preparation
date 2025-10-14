
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(V,0);
        vector<vector<int>> res;//connected_components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int> comp;
                dfs(i,adj,vis,comp);
                res.push_back(comp);
            }
        }
        return res;
    }
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& comp){
        vis[node]=1;
        comp.push_back(node);
        for(int v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis,comp);
            }
        }
    }
};
