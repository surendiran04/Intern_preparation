class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        queue<pair<int,pair<int,int>>> q; //using queue since stops in inc by 1 (unit increment)
        q.push({0,{src,0}});// {stops,node,cost}
        vector<int> cost(n,INT_MAX);
        while(!q.empty()){
            auto it=q.front();q.pop();
            int stops=it.first,node=it.second.first,costs=it.second.second;
            if(stops>k){
                continue;
            }
            for(auto f:adj[node]){
                int v=f.first,costs_v=f.second;
                if(costs+costs_v<cost[v] && stops<=k){
                    cost[v]=costs+costs_v;
                    q.push({stops+1,{v,cost[v]}});
                }
            }
        }
        return cost[dst]==INT_MAX?-1:cost[dst];
    }
};
