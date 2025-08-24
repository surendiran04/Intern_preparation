class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int u=0;u<n;u++){
            if(!vis[u]){
                cnt++;
                bfs(u,isConnected,vis,n);
            }
        }
        
        return cnt;
    }
    void bfs(int u,vector<vector<int>>& isConnected,vector<int>& vis,int n){
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=0;v<n;v++){
                if(!vis[v] && isConnected[u][v]==1){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
};
