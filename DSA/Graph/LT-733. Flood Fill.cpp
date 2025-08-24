// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
//Given a matrix,a new clr ,index which denotes the clr needs to be changed to new clr as well as for the for indices nearby(4-direction) and same image[sr][sc] clr
class Solution {
private:
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> mat=image;
         int initClr=image[sr][sc];
         dfs(image,mat,sr,sc,initClr,color);
         return mat;
    }
    void dfs(vector<vector<int>>& image,vector<vector<int>>& mat,int r,int c,int initClr,
    int color){
        mat[r][c]=color;
        int n=image.size(),m=image[0].size();
        for(int i=0;i<4;i++){
            int nr=dx[i]+r;
            int nc=dy[i]+c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initClr && mat[nr][nc]!=color){
                dfs(image,mat,nr,nc,initClr,color);
            }
        }
    }
};
