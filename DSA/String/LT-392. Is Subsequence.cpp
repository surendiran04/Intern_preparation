// Input: s = "abc", t = "ahbgdc"
// Output: true
// Input: s = "axc", t = "ahbgdc"
// Output: false
//checking if all the characters of s are present in t if s is "" then it is also true
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n==0){
            return true;
        }
        int i=0,j=0;
        int count=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                count++;
                i++;
                j++;
            }
            if(s[i]!=t[j]){
                j++;
            }
            if(count==n) return true;
        }
        return false;
    }
};
