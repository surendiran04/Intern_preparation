// TC: O(n * m * log(n * m))

class Solution {
  public:
    int n,m;
    int countDistinctIslands(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,i,j,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,
    int i0,int j0,vector<pair<int,int>>& vec){
        vec.push_back({i-i0,j-j0});  //reducing the index - base to find out the shape
        vis[i][j]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(nx,ny,vis,grid,i0,j0,vec);
            }
        }
    }
};
