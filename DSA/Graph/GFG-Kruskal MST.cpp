class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);//0-based indexing
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(begin(edges),end(edges),[&](vector<int>& a,vector<int>&b){
            if(a[2]==b[2]){
                return a[0]<b[0];
            }
            return a[2]<b[2];
        });
        // for(auto it:edges){
        //     cout<<it[0]<<"-"<<it[1]<<" :"<<it[2]<<endl;
        // }
        DisjointSet ds(V);
        int sum=0;
        vector<pair<int,int>> mst;
        for(auto e:edges){
            int u=e[0],v=e[1],wt=e[2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                sum+=wt;
                mst.push_back({u,v});
                ds.unionBySize(u,v);
            }
        }
        // for(auto it : mst){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return sum;
    
    }
};
