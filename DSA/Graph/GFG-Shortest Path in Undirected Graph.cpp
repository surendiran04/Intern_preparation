Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V=adj.size();
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();q.pop();
            for(int i:adj[node]){
                if(dist[node]+1<dist[i]){
                    dist[i]=dist[node]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
