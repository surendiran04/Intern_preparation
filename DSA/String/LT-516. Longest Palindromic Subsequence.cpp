// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
class Solution {
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(begin(t),end(t));  // similiar to lcs 
        return solve(s,t,n-1,n-1);
    }
    int solve(string& s,string& t,int i,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }   
        if(s[i]==t[j]){
            return dp[i][j]=1+solve(s,t,i-1,j-1);
        }
        return dp[i][j]=max(solve(s,t,i-1,j),solve(s,t,i,j-1));
     }
};
