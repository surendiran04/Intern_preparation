// You are given a string s and two integers x and y. You can perform two types of operations any number of times.
// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

// Example 2:

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points=0;
        pair<int,string> high_priority={(x>y)?x:y,(x>y)?"ab":"ba"};
        pair<int,string> low_priority={(x>y)?y:x,(x>y)?"ba":"ab"};

        pair<int,string> ans=calculatePoints(s,high_priority);
        points+=ans.first;
        ans=calculatePoints(ans.second,low_priority);
        points+=ans.first;
        return points;
    }
    pair<int,string> calculatePoints(string s,pair<int,string> p){
        string st;
        int points=0;
        for(char c:s){
            if(!st.empty() && st.back()==p.second[0] && c==p.second[1]){
                st.pop_back();
                points+=p.first;
            }else{
                st.push_back(c);
            }
        }
        return {points,st};
    }
};

class Solution { 
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        vector<char> stack;
        for (char ch : s) { 
            if (ch == top[1] && !stack.empty() && stack.back() == top[0]) {
                res += top_score;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        vector<char> new_stack;
        for (char ch : stack) {  
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                res += bot_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }

        return res;
    }
};
