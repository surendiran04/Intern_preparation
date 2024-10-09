// Input: s = "())"
// Output: 1
// Example 2:

// Input: s = "((("
// Output: 3
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){
            if(!st.empty() && c==')' && st.top()=='('){
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.size();
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) { //O(1) space
        int open = 0, close = 0;
        for (auto c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};
