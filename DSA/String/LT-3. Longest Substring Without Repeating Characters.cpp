// Example 1:
// Input: s = "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3.
  
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
  
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // Initialize an array to store the last index of each character
    int maxLen = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (lastIndex[c] >= start) {
            // If the character is already in the current substring, update the start position
            start = lastIndex[c] + 1;
        }
        lastIndex[c] = i;
        maxLen = max(maxLen, i - start + 1);
    }

    return maxLen;
    }
        
};
