class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }
        // Length mismatch check
    if (pattern.length() != words.size()) return false;

    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

    for (int i = 0; i < pattern.length(); ++i) {
        char c = pattern[i];
        string w = words[i];

        if (charToWord.count(c)) {
            if (charToWord[c] != w) return false;
        } else {
            if (wordToChar.count(w)) return false;
            charToWord[c] = w;
            wordToChar[w] = c;
        }
    }

    return true;
        
    }
};
