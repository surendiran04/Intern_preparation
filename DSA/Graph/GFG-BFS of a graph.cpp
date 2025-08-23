// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps: 
// Visit 0 → Output: 0 
// Visit 2 (first neighbor of 0) → Output: 0, 2 
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> ls;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ls.push_back(node);
            for(int i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
            
        }
        return ls;
    }
};
