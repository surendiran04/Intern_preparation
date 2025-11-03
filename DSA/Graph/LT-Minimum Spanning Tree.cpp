class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) { //TC: O(ElogV)
        vector<vector<vector<int>>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> vis(V,0);
        vector<pair<int,int>> mst;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        
        int sum=0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node])continue;            
            if(parent!= -1)
             mst.push_back({node,parent});
            vis[node] = 1;
            sum += dis;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];
                
                if(!vis[adjNode]){
                    pq.push({edgeW,{adjNode,node}});
                }
            }
        }
        //printing mst
        // for(auto it : mst){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        return sum;
    
    }
};
