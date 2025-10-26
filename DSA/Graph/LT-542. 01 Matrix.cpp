class Solution {
public:
    struct xyz{
        int x,y,steps;
        xyz(int a,int b,int c){
            x=a;
            y=b;
            steps=c;
        }
    }; 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<xyz> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push(xyz(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            int p=q.size();
            for(int i=0;i<p;i++){
                auto [x,y,steps]=q.front();
                q.pop();
                dist[x][y]=steps;
                for(int i=0;i<4;i++){
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    if(isValid(nx,ny,n,m,vis)){
                        vis[nx][ny]=1;
                        q.push({nx,ny,steps+1});
                    }
                }

            }
        }
        return dist;
    }
    bool isValid(int nx,int ny,int n,int m,vector<vector<int>>& vis){
        return (nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]);
    }
};
