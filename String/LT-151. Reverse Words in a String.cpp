// Input: s = "the sky is blue"
// Output: "blue is sky the"
class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        string result;
        int n=words.size();
        for (int i = n-1; i>=0;i--) {
            if (i < n-1) {
                result += " ";
            }
            result += words[i];
        }
        return result;
    }
};
