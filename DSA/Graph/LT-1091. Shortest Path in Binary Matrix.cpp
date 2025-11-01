class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) { //TC:SC: O(n^2)
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();q.pop();
            int dis=it.first,row=it.second.first,col=it.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0){
                        continue;
                    }
                    int nr=row+i,nc=col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                        dist[nr][nc]=dis+1;
                        if(nr==n-1 && nc==m-1){
                            return dist[nr][nc];
                        }
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1]==INT_MAX?-1:dist[n-1][m-1];
    }
};
