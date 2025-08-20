// You are given a string s. You can convert s to a palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.
// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

class Solution {
public:
    string shortestPalindrome(string s) { //BruteForce --fails bigger TC's
        int n=s.length();
        int i=n-1;
        if(check(s)){
            return s;
        }
        while(i>=0){
            string sub=s.substr(i,n-i);
            reverse(sub.begin(),sub.end());
            sub=sub+s;
            if(check(sub)){
                return sub;
            }
            i--;
        } 
        return s; 
    }
    bool check(string s){
        int n=s.length();
        for(int i=0,j=n-1;i<=j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        rev=s+"#"+rev;
        int n=rev.size();
        vector<int> lps(n,0);
        int len=0;
        for(int i=1;i<n;){
            if(rev[i]==rev[len]){
                lps[i++]=++len;
            }else if(len){
                len=lps[len-1];
            }else{
                lps[i++]=0;
            }
        }
        string suffix=s.substr(lps.back());
        reverse(suffix.begin(),suffix.end()); 
        return suffix+s; 
    }
};
