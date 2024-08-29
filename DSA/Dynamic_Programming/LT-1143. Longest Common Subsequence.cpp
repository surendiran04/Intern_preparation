class Solution {    //T(n) - O(n*m)  
public:             //S(n) - O(n*m) + O(n+m)   since the O(n+m) is for auxilary space(in last else statement there are 2 calls one'll be stored in dp,another'll use stack space
    int longestCommonSubsequence(string text1, string text2) { //passed 46/47 cases one case got TLE
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1)); //memoization 
        return lcs(n-1,m-1,text1,text2,dp);
    }
    int lcs(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+lcs(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
    }
};

class Solution { // Tabulation/Bottom up approach
public:
    int longestCommonSubsequence(string text1, string text2) { //it reduced the extra calls
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
