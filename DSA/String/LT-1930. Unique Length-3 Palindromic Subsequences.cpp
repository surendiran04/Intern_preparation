class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int countPalindromicSubsequence(string s) {
    vector<int> first(26, -1); 
    vector<int> last(26, -1); 

    // Record the first and last occurrence of each character
    for (int i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        if (first[index] == -1) {
            first[index] = i;
        }
        last[index] = i;
    }

    unordered_set<string> uniquePalindromes;
    // Check for unique palindromes
    for (int i = 0; i < 26; ++i) {
        if (first[i] != -1 && first[i] < last[i]) {
            unordered_set<char> middleChars;
            for (int j = first[i] + 1; j < last[i]; ++j) {
                middleChars.insert(s[j]);
            }
            // Form palindromes and add to the set
            for (char middle : middleChars) {
                string palindrome = string(1, 'a' + i) + middle + string(1, 'a' + i);
                uniquePalindromes.insert(palindrome);
            }
        }
    }

    return uniquePalindromes.size();
}

int main() {
    string s1 = "aabca";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << countPalindromicSubsequence(s1) << endl;

    string s2 = "adc";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << countPalindromicSubsequence(s2) << endl;

    string s3 = "bbcbaba";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << countPalindromicSubsequence(s3) << endl;

    return 0;
}
