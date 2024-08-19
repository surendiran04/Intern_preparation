// Input: ransomNote = "a", magazine = "b"
// Output: false
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// the characters that are in ransomeNote must be present in magazine else false
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) {
                dictionary[c] = 1;
            } else {
                dictionary[c]++;
            }
        }
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
