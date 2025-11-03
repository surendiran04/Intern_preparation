class Solution {
private:
    int timer=0;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>& vis,
    vector<int>& time,vector<int>& lower_time,vector<vector<int>>& bridges){
        vis[node]=1;
        time[node]=lower_time[node]=timer;
        timer++;
        for(int v:adj[node]){
            if(v==parent){
                continue;
            }
            if(!vis[v]){
                dfs(v,node,adj,vis,time,lower_time,bridges);
                lower_time[node]=min(lower_time[node],lower_time[v]); //someother way smaller node
                if(lower_time[v]>time[node]){ //it didn't have anyother path other than from it
                    bridges.push_back({node,v});
                }
            }else{
                lower_time[node]=min(lower_time[node],lower_time[v]); //someother way smaller node
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        vector<int> time(n),lower_time(n);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,vis,time,lower_time,bridges);
        return bridges;
    }
};
