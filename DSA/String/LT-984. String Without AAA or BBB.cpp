// s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
// The substring 'aaa' does not occur in s, and
// The substring 'bbb' does not occur in s.

// Example 1:
// Input: a = 1, b = 2
// Output: "abb"
// Explanation: "abb", "bab" and "bba" are all correct answers.
// Example 2:
// Input: a = 4, b = 1
// Output: "aabaa"
  
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a>0 || b>0){
           bool writeA=false;
           int l=ans.length();
           if(l>=2 && ans[l-1]==ans[l-2]){
            if(ans[l-1]=='b'){
                writeA=true;
            }
           }else{
            if(a>=b){
                writeA=true;
            }
           }
           if(writeA){
            ans+='a';
            a--;
           }else{
            ans+='b';
            b--;
           }
        }
        return ans;
    }
};
