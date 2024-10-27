class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        int max_size=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;  //If the 3 adjacent sides are 1 then it is a sqaure
                    }
                    max_size = max(max_size,dp[i][j]);
                }
            }
        }
        return max_size*max_size;
    }
};
