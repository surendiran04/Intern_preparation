class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>> time(n,vector<int>(m,1e9));
        time[0][0]=grid[0][0];
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        while(!pq.empty()){
            auto temp=pq.top();pq.pop();
            int t=temp[0],x=temp[1],y=temp[2];
            if(x==n-1 && y==m-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(isValid(nx,ny,n,m)){
                    int newTime=(t>=grid[nx][ny])?t:t+abs(grid[nx][ny]-t);
                    if(newTime<time[nx][ny]){
                        time[nx][ny]=newTime;
                        pq.push({time[nx][ny],nx,ny});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
    bool isValid(int nx,int ny,int n,int m){
        return nx>=0 && nx<n && ny>=0 &&ny<m;
    }
};
