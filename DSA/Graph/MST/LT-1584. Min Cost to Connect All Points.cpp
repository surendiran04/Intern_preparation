lass Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n<2){
            return 0;
        }
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                int cost=abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1]);
                adj[i].push_back({j,cost});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(auto it:adj[i]){
        //         cout<<i<<"-"<<it.first<<": "<<it.second<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(n,0);
        using T=tuple<int,int,int>; //cost,node,parent
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0,-1});
        int totalcost=0;
        vector<T> mst;
        while(!pq.empty()){
            auto [cost,node,parent]=pq.top();pq.pop();
            if(vis[node])
                continue;
            if(parent!=-1){
                mst.push_back({node,parent,cost});
            }
            vis[node]=1;
            totalcost+=cost;
            for(auto it:adj[node]){
                int v=it.first;
                int edgeWt=it.second;
                if(!vis[v]){
                    pq.push({edgeWt,v,node});
                }
            }

        }
        for(auto [node,parent,cost]:mst){
            cout<<node<<"-"<<parent<<": "<<cost<<endl;
        }
        return totalcost;
    }
};
