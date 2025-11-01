class Solution {
 private:
 void dfs(int u,vector<vector<pair<int,int>>>& adj,vector<int>& vis,stack<int>& st){
     vis[u]=1;
     for(auto it:adj[u]){
         if(!vis[it.first]){
             dfs(it.first,adj,vis,st);
         }
     }
     st.push(u);
 }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) { //O(V+E)
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto e:edges){
            int u=e[0],v=e[1],wt=e[2];
            adj[u].push_back({v,wt});
        }
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
        if(st.top() != 0 ){ //these are unreachable nodes so pop it out
            st.pop();
        }else{
            break;
        }
        }
        while(!st.empty()){
            int node=st.top();st.pop();
            for(auto it:adj[node]){
                int v=it.first,wt=it.second;
                if(dist[node]+wt<dist[v]){  //dist[v]=min(dist[v],wt+dist[node]);
                    dist[v]=dist[node]+wt;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){ //unreachable nodes
                dist[i]=-1;
            }
        }
        return dist;
    }
};
