// Reach from (0,0) -> (m,n) by moving only down and right return the number of combinations
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
