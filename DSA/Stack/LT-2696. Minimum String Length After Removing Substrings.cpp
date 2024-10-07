//you can remove any occurrence of one of the substrings "AB" or "CD" from s and return the size of s if not return same size
// Input: s = "ABFCACDB"
// Output: 2
// Explanation: We can do the following operations:
// - Remove the substring "ABFCACDB", so s = "FCACDB".
// - Remove the substring "FCACDB", so s = "FCAB".
// - Remove the substring "FCAB", so s = "FC".
// So the resulting length of the string is 2.
class Solution { //similiar to valid paranthesis
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((c == 'B' && st.top() == 'A') ||
                (c == 'D' && st.top() == 'C')) ){
                st.pop();
                count += 2;
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};
