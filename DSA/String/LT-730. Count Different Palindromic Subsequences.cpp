// Input: s = "bccb"
// Output: 6
// Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
// Note that 'bcb' is counted only once, even though it occurs twice.
class Solution {
public:
    int MOD=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return solve(s,dp,0,n-1);
    }
    int solve(string& s,vector<vector<long long>>& dp,int i,int j){
        if(j==i){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
         long ans = 0;
        if (s[i] == s[j]) {
            int l = i + 1, r = j - 1;
            while (l <= r && s[l] != s[i]) l++;
            while (l <= r && s[r] != s[j]) r--;

            if (l > r) {
                // no same char inside
                ans = 2 * solve(s,dp,i+1, j-1) + 2;
            } else if (l == r) {
                // one same char inside
                ans = 2 * solve(s,dp,i+1, j-1) + 1;
            } else {
                // multiple same chars inside
                ans = 2 * solve(s,dp,i+1, j-1) - solve(s,dp,l+1, r-1);
            }
        } else {
            ans = solve(s,dp,i+1, j) + solve(s,dp,i, j-1) - solve(s,dp,i+1, j-1);
        }

        ans %= MOD;
        if (ans < 0) ans += MOD;
        return dp[i][j] = ans;
    }
};


class Solution {
public:
    int mod=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return rec(s,dp,0,n-1);
    }
    int rec(string& s,vector<vector<long long>>& dp,int i,int j){ //Not unique palindrome - it'll count all palaindrome
        if(j==i){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            dp[i][j]=(1+rec(s,dp,i+1,j)+rec(s,dp,i,j-1))%mod;
        }else{
            dp[i][j]=((rec(s,dp,i+1,j)+rec(s,dp,i,j-1)-rec(s,dp,i+1,j-1))%mod+mod)%mod;
        }
        return dp[i][j];
    }
};
