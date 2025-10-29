class Solution {
public:
   vector<vector<int>> vis;
   int n,m;
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && dfs(grid,i,j,-1,-1,grid[i][j])){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& grid,int x,int y,int pi,int pj,char c){
        vis[x][y]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                continue;
            }
            if(grid[nx][ny]!=c){
                continue;
            }
            if(nx==pi && ny==pj){
                continue;
            }
            if(vis[nx][ny]){
                return true;
            }
            if(dfs(grid,nx,ny,x,y,c)){
                return true;
            }
        }
        return false;
    }
};
// Time Complexity	DFS: O(m × n)	BFS:O(m × n)
// Space Complexity	DFS:O(m × n) for visited + recursion stack	BFS: O(m × n) for visited + queue
#include <bits/stdc++.h> //BFS
using namespace std;

class Solution {
public:
    struct Cell {
        int x, y;
        int px, py;
        char ch;
        Cell(int _x, int _y, int _px, int _py, char _ch)
            : x(_x), y(_y), px(_px), py(_py), ch(_ch) {}
    };

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    queue<Cell> q;
                    q.push(Cell(i, j, -1, -1, grid[i][j]));
                    vis[i][j] = 1;

                    while (!q.empty()) {
                        Cell cur = q.front(); q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = cur.x + dx[k];
                            int ny = cur.y + dy[k];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                                continue;
                            if (grid[nx][ny] != cur.ch)
                                continue;
                            if (nx == cur.px && ny == cur.py)
                                continue;

                            if (vis[nx][ny])
                                return true;  // cycle detected

                            vis[nx][ny] = 1;
                            q.push(Cell(nx, ny, cur.x, cur.y, cur.ch));
                        }
                    }
                }
            }
        }
        return false;
    }
};
