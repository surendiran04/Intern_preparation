class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) { //DFS TC:O(V+E)
        vector<vector<int>> adj(V);
        for(vector<int> e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(V,0),pathVis(V,0); //we can use only vis and mark it as 2 for path visited and in the end we mark it as vis[u]=1 to mark as visited;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int u,vector<int>& vis,vector<int>& pathVis,vector<vector<int>>& adj){
     vis[u]=1;
     pathVis[u]=1;
     for(int v:adj[u]){
         if(!vis[v]){
             if(dfs(v,vis,pathVis,adj)){
                 return true;
             }
         }else if(pathVis[v]){
             return true;
         }
     }
     pathVis[u]=0;
     return false;
    }
};
class Solution {
    public: bool isCyclic(int V, vector < vector < int >> & edges) { //BFS TC:O(V+E)
        vector < vector < int >> adj(V);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector < int > indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v: adj[u]) {
                indegree[v]++;
            }
        }
        queue < int > q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector < int > topo; //just use a count=0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node); //cnt++;
            for (int v: adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return topo.size() != V;
    }
};
