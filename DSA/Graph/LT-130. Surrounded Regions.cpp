class Solution {
public:
    int n,m;
    void solve(vector<vector<char>>& board) { //Boundary Traversal 
        n=board.size();
        m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,true));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j] && (i==0 || j==0 || i==n-1 || j==m-1)){
                    dfs(board,vis,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int i,int j){
        vis[i][j]=false;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && vis[nx][ny]){
                dfs(board,vis,nx,ny);
            }
        }
    }
};
