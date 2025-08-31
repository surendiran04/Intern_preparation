// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){   // 1st col way
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<m;j++){  //1st row way
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        for(int i=1;i<n;i++){  //finding the min way by adding current i,j with the min one 
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
