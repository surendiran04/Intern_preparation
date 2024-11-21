class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // Initialize grid

        // Mark guards as 1 and walls as 2
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        // Directions for north, east, south, west
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Mark guarded cells
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto dir : directions) {
                int dx = dir.first, dy = dir.second;
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       grid[nx][ny] != 1 && grid[nx][ny] != 2) {
                    grid[nx][ny] = 3; // Mark cell as guarded
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unguarded++;
                }
            }
        }

        return unguarded;
    }
};
