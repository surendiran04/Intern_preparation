// similiar to LT-392. Is subsequence
// Input: s = "coaching", t = "coding"
// Output: 4
// Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
// Now, t is a subsequence of s ("coachingding").
// It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
// Example 2:

// Input: s = "abcde", t = "a"
// Output: 0
// Explanation: t is already a subsequence of s ("abcde").
// Example 3:

// Input: s = "z", t = "abcde"
// Output: 5

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length(),m=t.length();
        int i=0,j=0;
        while(i<n && j<m){
            if(t[j]==s[i]){
                j++;
            }
            i++;
        }
        return (j==m)?0:(m-j);
    }
};
