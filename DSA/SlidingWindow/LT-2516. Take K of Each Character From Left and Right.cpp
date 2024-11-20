// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost 
//character of s, or the rightmost character of s.Return the minimum number of minutes needed for you to take at least k of each character, 
// or return -1 if it is not possible to take k of each character.

// Example 1:
// Input: s = "aabaaaacaabc", k = 2
// Output: 8
  
class Solution {  //we have to find the maximum substring which is not needed 
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        if (count['a'] < k || count['b'] < k || count['c'] < k) return -1;

        int n = s.size(), required_a = count['a'] - k, required_b = count['b'] - k, required_c = count['c'] - k;
        int left = 0, max_window = 0;
        unordered_map<char, int> window_count;

        for (int right = 0; right < n; ++right) {
            window_count[s[right]]++;
            while (window_count['a'] > required_a || window_count['b'] > required_b || window_count['c'] > required_c) {
                window_count[s[left]]--;
                left++;
            }
            max_window = max(max_window, right - left + 1);
        }
        return n - max_window;
    }
};
