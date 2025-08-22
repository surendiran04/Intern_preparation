class Solution {
public:
    bool check(int i,int j,string &s,string &p,vector<vector<int>>& dp){ //exponential
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=check(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]= check(i-1,j,s,p,dp) || check(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return check(n-1,m-1,s,p,dp);
    }
};

class Solution {           //SC-O(n*m)+O(n+m) TC-O(n*m)
public:
    bool check(int i,int j,string &s,string &p,vector<vector<int>>& dp){ //Memoized code
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=check(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]= check(i-1,j,s,p,dp) || check(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return check(n-1,m-1,s,p,dp);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) { //Use 1-based Indexing
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); //SC-O(n*m) TC-O(n*m)
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

