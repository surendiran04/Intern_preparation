// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell\
//you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform

// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxMoves = 0;

        for (int col = n - 2; col >= 0; --col) {
            for (int row = 0; row < m; ++row) {
                if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row - 1][col + 1] + 1);
                }
                if (grid[row][col] < grid[row][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row][col + 1] + 1);
                }
                if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row + 1][col + 1] + 1);
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            maxMoves = max(maxMoves, dp[row][0]);
        }
        return maxMoves;
    }
};
