//The order of characters in s needs to be preserved in t 
// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Input: s = "aaaaaa", t = "bbaaaa"
// Output: false


class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=0,j=0;
       int n=s.length(),m=t.length();
       while(i<n && j<m){
        if(s[i]==t[j]){
            i++;
        }
        j++;
       }
       return i==n;
    }
};
