class Solution {
private:
 int dx[4]={-1,0,1,0};
 int dy[4]={0,-1,0,1};
 void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){ //O(n*m)
    vis[row][col]=1;
    int n=grid.size(),m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=dx[i]+r;
            int nc=dy[i]+c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
 }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
