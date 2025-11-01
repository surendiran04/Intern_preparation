class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { //DFS
        int V=graph.size();
        vector<int> vis(V,0),pathVis(V,0),checkcycle(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,checkcycle,graph);
            }
        }
        vector<int> safe_state;
        for(int i=0;i<V;i++){
            if(!checkcycle[i]){ //nodes which are not a part of cycle is a safe node
                safe_state.push_back(i);
            }
        }
        return safe_state;
    }
  bool dfs(int u,vector<int>& vis,vector<int>& pathVis,vector<int>& checkcycle,
    vector<vector<int>>& adj){        
     vis[u]=1;
     pathVis[u]=1;
     checkcycle[u]=1;
     for(int v:adj[u]){
        if(!vis[v]){
            if(dfs(v,vis,pathVis,checkcycle,adj)){
                return true;
            }
        }else if(pathVis[v]){
            return true;
        }
     }
     checkcycle[u]=0;
     pathVis[u]=0;
     return false;
    }
};

//Chnaging the indegree to outdegree's then doing the normal linear ordering , the nodes which or not part of the ordering means they're stuck in a cycle
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { //BFS Topological sort
        int V=graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);
        for(int u=0;u<V;u++){
            for(int v:graph[u]){
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int v:adjRev[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        sort(begin(safeNodes),end(safeNodes));
        return safeNodes;
    }
};
