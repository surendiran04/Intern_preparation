// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//   Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(128, -1); 
    int maxLen = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }
        lastIndex[c] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
    }   
};
