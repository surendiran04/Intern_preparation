// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:
// Input: s = "abcde", goal = "abced"
Output: false
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string s1=s+s;
        int n=goal.length();
        for(int i=0;i<s1.length();i++){
            if(s1[i]==goal[0]){
                if(s1.substr(i,n)==goal){
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubledString = s + s;
        return doubledString.find(goal) < doubledString.length();
    }
};
