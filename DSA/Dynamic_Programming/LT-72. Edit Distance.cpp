// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
     //1+f(i-1,j) - delete
     //1+f(i,j-1) - insert
     //1+f(i-1,j-1) - replace
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp))); //simply trying out every possible cases with memoization
    }
};

class Solution {  //avoiding SC - O(n+m) recursive calls by 1 based indexing
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==0){
            return j;
        }
        if(j==0){
            return i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
};

class Solution { //tabulation - 100%
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

int editDistance(string& S1, string& S2) { //1D arrays approach
    int n = S1.size();
    int m = S2.size();

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++) {
        cur[0] = i;
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                cur[j] = prev[j - 1];
            } else {
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; // Update the previous row with the current row
    }
    return cur[m];
}
