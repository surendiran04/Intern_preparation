class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V=adj.size();                           //TC:O(E logV)
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; //min-heap
        q.push({0,src});
        while(!q.empty()){
            auto [dis,node]=q.top();
            q.pop();
            for(int i:adj[node]){
                if(dist[node]+1<dist[i]){
                    dist[i]=dist[node]+1;
                    q.push({dist[i],i});
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
