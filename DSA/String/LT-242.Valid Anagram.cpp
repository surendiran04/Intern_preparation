// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
// Input: s = "rat", t = "car"
// Output: false
  
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (auto x : s) {
            count[x]++;
        }
        for (auto x : t) {
            count[x]--;
        }
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }    
        return true;
    }
};
