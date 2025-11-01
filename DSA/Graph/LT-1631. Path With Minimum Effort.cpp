class Solution {
public:
    struct Node{  // TC: O(M∗N∗Log(M∗N))
        int effort,row,col;
        Node(int e,int r,int c){
            effort=e;
            row=r;
            col=c;
        }
    };
    struct compare{
      bool operator()(Node& a,Node& b){
        if(a.effort==b.effort){
            if(a.row==b.row){
                return a.col>b.col;
            }
            return a.row>b.row;
        }
        return a.effort>b.effort; // min-heap by first
      }
    };
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<Node,vector<Node>,compare> q;
        q.push({0,0,0});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.top();q.pop();
            int eff=it.effort,row=it.row,col=it.col;
            if(row==n-1 && col==m-1){
                return eff;
            }
            for(int i=0;i<4;i++){
                int nr=row+dx[i],nc=col+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neweff=max(abs(grid[nr][nc]-grid[row][col]),eff);
                    if(neweff<dist[nr][nc]){
                        dist[nr][nc]=neweff;
                        q.push({dist[nr][nc],nr,nc});
                    }
                        
                }
                    
            }
        }
        return 0;
    }
};
