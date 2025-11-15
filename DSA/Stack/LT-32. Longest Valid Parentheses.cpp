class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        st.push(-1);
        int max_size=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    max_size=max(max_size,i-st.top());
                }
            }
        }
        return max_size;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) { //greedy approach
        int left = 0, right = 0, ans = 0;

        // left → right
        for (char c : s) {
            if (c == '(') left++;
            else right++;

            if (left == right) ans = max(ans, 2 * right);
            else if (right > left) left = right = 0;
        }

        left = right = 0;
        // right → left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) ans = max(ans, 2 * left);
            else if (left > right) left = right = 0;
        }

        return ans;
    }
};
