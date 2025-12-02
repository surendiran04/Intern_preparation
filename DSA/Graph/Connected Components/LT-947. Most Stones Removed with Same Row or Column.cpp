class DSU{
    vector<int> parent,size; //DSU | row - col mapping | map
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
             parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0;
        for(auto s:stones){
            maxRow=max(maxRow,s[0]);
            maxCol=max(maxCol,s[1]);
        }
        DSU ds(maxRow+maxCol+2);
        unordered_map<int,int> uniqueStones;
        for(auto s:stones){
            int u=s[0],v=maxRow+s[1]+1;
            ds.unionBySize(u,v);
            uniqueStones[u]=1;
            uniqueStones[v]=1;
        }
        int nc=0;
        for(auto s:uniqueStones){
            if(ds.findParent(s.first)==s.first){
                nc++;
            }
        }
        return stones.size()-nc;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {  //DFS 
        int n=stones.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(!vis[i]){
                dfs(adj,vis,cnt,i);   //No of nodes in the cluster - 1 needs to be removed
                ans+=cnt-1;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int& cnt,int u){
        vis[u]=1;
        cnt++;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(adj,vis,cnt,v);
            }
        }
    }
};
