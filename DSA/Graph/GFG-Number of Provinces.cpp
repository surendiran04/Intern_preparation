// Input:[[1, 0, 1],[0, 1, 0],[1, 0, 1]]
// Output:2
// Explanation:
// The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province.
// City 2 has no path to city 1 or city 3 hence it belongs to another province.

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,adj,V,i);
            }
        }
        return cnt;
    }
    void dfs(vector<int>& vis,vector<vector<int>>& adj,int n,int u){
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v] && adj[u][v]==1){
                dfs(vis,adj,n,v);
            }
        }
    }
};
