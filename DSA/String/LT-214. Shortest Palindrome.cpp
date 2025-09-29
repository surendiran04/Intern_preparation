// You are given a string s. You can convert s to a palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.
// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

#include <bits/stdc++.h>
using namespace std;
// check if substring s[0..end] is palindrome
bool isPalindrome(const string &s, int end) {
    int i = 0, j = end;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

string shortestPalindrome(string s) {
    int n = s.size();
    int longestPalPrefix = 0;

    // find longest palindromic prefix
    for (int end = n - 1; end >= 0; end--) {
        if (isPalindrome(s, end)) {
            longestPalPrefix = end + 1;
            break;
        }
    }

    // suffix = part after palindromic prefix
    string suffix = s.substr(longestPalPrefix);
    reverse(suffix.begin(), suffix.end());

    return suffix + s;
}

int main() {
    cout << shortestPalindrome("aacecaaa") << endl; // "aaacecaaa"
    cout << shortestPalindrome("abcd") << endl;     // "dcbabcd"
    return 0;
}


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
