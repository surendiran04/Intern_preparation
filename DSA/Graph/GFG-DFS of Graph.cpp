// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output: [0, 2, 4, 3, 1]
// Explanation: Starting from 0, the DFS traversal proceeds as follows:
// Visit 0 → Output: 0 
// Visit 2 (the first neighbor of 0) → Output: 0, 2 
// Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
// Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
// Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> ls;
        dfs(0,ls,vis,adj);
        return ls;
    }
    void dfs(int node,vector<int>& list,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=1;
        list.push_back(node);
        for(int i:adj[node]){
            if(!vis[i]){
                dfs(i,list,vis,adj);
            }
        }
    }
};
