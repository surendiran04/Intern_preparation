// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:
// Input: s = "cbbd"
// Output: "bb"
 
class Solution {
public:
    string longestPalindrome(string s) { //O(n^3) didn't pass all TC's
        int n=s.length();
        for(int i=n;i>0;i--){
            for(int j=0;j<=n-i;j++){
                if(check(s,j,i+j)){
                    return s.substr(j,i);
                }
            }
        }
        return "";
    }
    bool check(string s,int i,int j){
        j--;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(string s) { //Expand from center for odd and even sizes
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string odd=expand(s,i,i);
            if(odd.size()>ans.size()){
                ans=odd;
            }
            string even=expand(s,i,i+1);
            if(even.size()>ans.size()){
                ans=even;
            }
        }
        return ans;
    }
    string expand(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
};
