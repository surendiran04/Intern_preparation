// You are given a string s and a pattern string p, where p contains exactly one '*' character.
// The '*' in p can be replaced with any sequence of zero or more characters.
// Return true if p can be made a substring of s, and false otherwise.

// Example 1:
// Input: s = "leetcode", p = "ee*e
// Output: true
// Explanation:
// By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.

// Example 2
// Input: s = "car", p = "c*v"
// Output: false
// Explanation:
// There is no substring matching the pattern.

// Example 3:
// Input: s = "luck", p = "u*"
// Output: true
// Explanation:
// The substrings "u", "uc", and "uck" match the pattern.

class Solution {
public:
    bool hasMatch(string s, string p) {
        int x=p.find('*');
        string p1=p.substr(0,x);
        string p2=p.substr(x+1);
        int left=s.find(p1);
        int right=s.rfind(p2);
        return left!=-1 && right!=-1 && left+p1.length()<=right;
    }
};
