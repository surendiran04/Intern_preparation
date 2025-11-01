class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) { //BFS TC:O(V+E)
        vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> indegree(V,0);
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return topo;
    }
};

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) { //DFS TC:O(V+E)
        vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st){
        vis[i]=1;
        for(int u:adj[i]){
            if(!vis[u]){
                dfs(u,adj,vis,st);
            }
        }
        st.push(i);
    }
};
