class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {
            "",    "",    "abc",  "def",
            "ghi", "jkl", "mno", "pqrs",
            "tuv", "wxyz"
        };
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    void backtrack(const string &digits, int index, string &current, 
                   vector<string> &result, const vector<string> &mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back();  // backtrack
        }
    }
};
