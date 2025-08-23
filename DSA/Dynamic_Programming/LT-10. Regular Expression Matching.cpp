class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0) {
            while (j >= 0) {
                if (p[j] == '*') j -= 2;
                else return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            bool zero = solve(i, j - 2, s, p, dp);
            if (p[j - 1] == s[i] || p[j - 1] == '.') {
                bool more = solve(i - 1, j, s, p, dp);
                return dp[i][j] = (zero || more);
            }
            return dp[i][j] = zero;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty string and empty pattern
        dp[0][0] = true;

        // Initialize for patterns like a*, a*b*, etc. (empty string case)
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                if (j >= 2) dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // zero occurrence
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // one or more
                    }
                }
            }
        }

        return dp[n][m];
    }
};
