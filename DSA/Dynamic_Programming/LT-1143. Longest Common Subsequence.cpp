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

#include <bits/stdc++.h>  //S(n) - O(n+m) approach
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Initialize two vectors to store the current and previous rows of the DP table
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[j - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1]; // Characters match, increment LCS length
            else
                cur[j] = max(prev[j], cur[j - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
}

int main() {
    string s1 = "acd";
    string s2 = "ced";

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
