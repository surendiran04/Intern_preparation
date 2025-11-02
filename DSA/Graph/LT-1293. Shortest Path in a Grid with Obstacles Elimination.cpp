class Solution {
struct State {     
    int x, y, dist, walls;
};
int dx[4] = {1, -1, 0, 0}; 
int dy[4] = {0, 0, 1, -1}; 
public:
    int shortestPath(vector<vector<int>>& grid, int k) { //TC:O(n * m * K*4) SC:O(n * m * K)
    int n, m;
    n = grid.size();   
    m = grid[0].size(); 
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false))); 
    queue<State> q;    
    q.push({0, 0, 0, 0});   
    visited[0][0][0] = true;     
    while (!q.empty()) {        
        auto cur = q.front();       
        q.pop();         
        if (cur.x == n-1 && cur.y == m-1) {      
            return cur.dist;       
        }        
            for (int i = 0; i < 4; i++) {           
                int nx = cur.x + dx[i];            
                int ny = cur.y + dy[i];              
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {          
                    int newWalls = cur.walls + (grid[nx][ny] == 1);             
                    if (newWalls <= k && !visited[nx][ny][newWalls]) {                 
                        visited[nx][ny][newWalls] = true;                   
                        q.push({nx, ny, cur.dist + 1, newWalls}); 
                    }             
                }        
            }     
        
    }     
    return -1;
    }
};
