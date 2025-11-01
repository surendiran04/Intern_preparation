class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        while(!q.empty()){
            auto [node,t]=q.front();q.pop();
            for(auto it:adj[node]){
                int v=it.first,wt=it.second;
                if(t+wt<time[v]){
                    time[v]=t+wt;
                    q.push({v,time[v]});
                }
            }
        }
        int maxtime=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX){
                return -1;
            }else{
                maxtime=max(maxtime,time[i]);
            }
        }
        return maxtime;
    }
};
