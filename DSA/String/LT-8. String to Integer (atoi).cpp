// Input: s = "42"
// Output: 42
// Input: s = " -042"
// Output: -42
// Input: s = "1337c0d3"
// Output: 1337
  
class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int sign = 1;
        int i = 0;

        while (i < s.length() && s[i] == ' ') i++;


        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign <= INT_MIN) return INT_MIN;
            if (ans * sign >= INT_MAX) return INT_MAX;
            i++;
        }

        return ans * sign;
    }
};
