class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,LLONG_MAX),ways(n,0);
        ways[0]=1;dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int node=it.second;
            auto dis=it.first;
            for(auto a:adj[node]){
                int wt=a.second,v=a.first;
                if(wt+dis<dist[v]){
                    dist[v]=wt+dis;
                    pq.push({dist[v],v});
                    ways[v]=ways[node];
                }else if(wt+dis==dist[v]){
                    ways[v]=(ways[node]+ways[v])%mod; //DP
                }
            }
        }
        return ways[n-1];
    }
};
