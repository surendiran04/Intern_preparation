// Input: N = 4
// arr = {10, 30, 5, 60}
// Output: 4500
class Solution{
public:
    int f(int i,int j,int arr[],vector<vector<int>> &dp){  //T(n)-O(n^3)
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
            if(steps<mini){
                mini=steps;
            }
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
};
