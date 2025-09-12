// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise. 

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered="";
        for(char ch:s){
            if(isalnum(ch)){
                filtered+=tolower(ch);
            }
        }
        for(int l=0,r=filtered.size()-1;l<r;l++,r--){
            if(filtered[l]!=filtered[r]){
                return false;
            }
        }
        return true;
    }
};
