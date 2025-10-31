class Solution {
private: //odd len cycle - no bipartite , even len cycle - bipartite ,linear - bipartite, we ensure even/odd cycle by colouring adjacent node by opp clrs
    bool dfs(int i,int clr,vector<vector<int>>& graph,vector<int>& color){
        color[i]=clr;
        for(int u:graph[i]){
            if(color[u]==-1){
                if(dfs(u,!clr,graph,color)==false){
                    return false;
                }
            }else if(color[u]==clr){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
