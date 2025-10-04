https://leetcode.com/discuss/post/5281339/stack-every-possible-conversion-infixpre-tc57/

The Infix to prefix conversion need to have an extra case when operator is '^' to check precendance(s[i])<=precedence(st.top()) else precendance(s[i])<precedence(st.top())
