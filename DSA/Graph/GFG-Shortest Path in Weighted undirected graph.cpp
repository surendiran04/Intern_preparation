class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V+1); //TC: O((V + E) log V)
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(V+1,1e9),parent(V+1); //SC:O(V + E)
        dist[1]=0;
        for(int i=1;i<=V;i++){
            parent[i]=i;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,1});
        while(!q.empty()){
            auto [dis,node]=q.top();
            q.pop();
            for(auto i:adj[node]){
                int v=i.first,wt=i.second;
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                    parent[v]=node;
                    q.push({dist[v],v});
                }
            }
        }
        vector<int> path;
        if(dist[V]==1e9){
            path.push_back(-1);
            return path;
        }
        int node=V;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);  //shortest path from 1 to n
        path.push_back(dist[V]);//ans
        reverse(begin(path),end(path));
        return path;
    }
};
