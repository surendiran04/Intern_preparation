// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Detect if any cycle in graph,given an edge matrix

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) { //TC:O(v+2E)+O(n) SC:O(n)
    vector<vector<int>> adj(V);
for (auto &e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(vis,adj,i,-1)){ //bfs(vis,adj,i)
                return true;
            }
        }
    }
      return false;  
    }
    bool bfs(vector<int>& vis,vector<vector<int>>& adj,int node){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
                auto [v,p]=q.front();
                q.pop();
                for(auto it:adj[v]){
                    if(!vis[it]){
                        q.push({it,v});
                        vis[it]=1;
                    }else if(p!=it){
                        return true;
                    }
                }
        }
        return false;
    }
    bool dfs(vector<int>& vis,vector<vector<int>>& adj,int node,int parent){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(vis,adj,it,node)){
                    return true;
                }
            }else if(parent!=it){
                return true;
            }
        }
        return false;
    }
};


class DSU{
private:
    vector<int> parent, union_size;

public:    
    DSU(int totalNodes){
        parent.resize(totalNodes, -1);
        // initially all are parent of iteslf and each set is having size 1
        for(int i=0; i<totalNodes; i++) parent[i] = i;
        union_size.resize(totalNodes, 1);
        
    }
    int findRepresentative(int node){
        if(parent[node]==node){
            return node;
        }
        // find parent and store it so no need to calculate it again and again(path compression) like we do in DP.
        return parent[node] = findRepresentative(parent[node]);
        
    }
    
    void doUnionBySize(int node1, int node2){
        int parent1 = findRepresentative(node1);
        int parent2 = findRepresentative(node2);
        
        // Both Node belong to same set
        if(parent1==parent2) return;
        
        // always merge smaller set to larger set to avoid longer path
        if(union_size[parent1] < union_size[parent2]){
            parent[parent1] = parent2;
            union_size[parent2] += union_size[parent1];
        }else{
            parent[parent2] = parent1;
            union_size[parent1] += union_size[parent2];
        }
    }
    
};

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        
        for(auto &i: edges){
            int parentU = dsu.findRepresentative(i[0]);
            int parentV = dsu.findRepresentative(i[1]);
            
            if(parentU == parentV) return true;
            dsu.doUnionBySize(i[0], i[1]);
        }
        
        return false;
        
    }
};
