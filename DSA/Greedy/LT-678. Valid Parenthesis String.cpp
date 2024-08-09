// Input: s = "(*))"
// Output: true
class Solution {
public:
    bool checkValidString(string s) {
         int leftMin = 0, leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;
        }
        
        return leftMin == 0;
    }
};
class Solution { //stack approach
public:
    bool checkValidString(string s) {
        stack<char> open;
        stack<char> asterisk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                asterisk.push(i);
            }
            else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }
                else if(!asterisk.empty()){
                    asterisk.pop();
                }
                else {
                    return false;
                }
            }
        }
        while(!open.empty() && !asterisk.empty()){
            if(open.top() > asterisk.top()) {
                return false;  // Invalid case where '(' is after '*' so '*' cannot balance it
            }
            open.pop();
            asterisk.pop();
        }
        return open.empty();
    }
};
