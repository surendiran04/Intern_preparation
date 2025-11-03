class DSU{
    vector<int> parent,size;
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
