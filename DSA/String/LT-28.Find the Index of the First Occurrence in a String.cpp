// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

class Solution {
public:
    int strStr(std::string haystack, std::string needle) { //Naive string matching
        if (needle.length() > haystack.length()) {
            return -1;
        }
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {  //KMP string matching
        int n=haystack.length(),m=needle.length();
        vector<int> lps=computeLPS(needle);
        for(int i=0,j=0;i<n;){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-j;
            }
            else if(i<n && haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
    vector<int> computeLPS(string pat){
        int n=pat.size();
        vector<int> lps(n,0);
        for(int i=1,len=0;i<n;){
            if(pat[i]==pat[len]){
                lps[i++]=++len;
            }else if(len){
                len=lps[len-1];
            }else{
                lps[i++]=0;
            }
        }
        return lps;
    }
};
