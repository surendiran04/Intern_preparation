// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.
 

// Example 1:
// Input: version1 = "1.2", version2 = "1.10"
// Output: -1
// Explanation:
// version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

// Example 2:
// Input: version1 = "1.01", version2 = "1.001"
// Output: 0
// Explanation:
// Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

// Example 3:
// Input: version1 = "1.0", version2 = "1.0.0.0"
// Output: 0

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            string t1 = "", t2 = "";
            while (i < n && version1[i] != '.') {
                t1 += version1[i];
                i++;
            }
            i++;
            while (j < m && version2[j] != '.') {
                t2 += version2[j];
                j++;
            }
            j++;
            int num1 = t1.empty() ? 0 : stoi(t1);
            int num2 = t2.empty() ? 0 : stoi(t2);
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
        }

        return 0;
    }
};
