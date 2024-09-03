// Input: s = "leetcode", k = 2
// Output: 6
// Explanation: The operations are as follows:
// - Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
// - Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
// - Transform #2: 33 ➝ 3 + 3 ➝ 6
// Thus the resulting integer is 6.
class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            int c=(s[i]-'a'+1);
            ans+=to_string(c);
        }
        int res=0;
        while(k>0){
            res=0;
            for(char c:ans){
                res+=c-'0';
            }
            ans=to_string(res);
            k--;
        }
        return res;
    }
};
