#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
        return ""; 
    }
    size_t minLength = strs[0].length();
    for (const std::string& str : strs) {
        minLength = min(minLength, str.length());
    }
    for (size_t i = 0; i < minLength; ++i) {
        char commonChar = strs[0][i];
        for (const string& str : strs) {
            if (str[i] != commonChar) { //if any of the string doesn't have the common char
                return strs[0].substr(0, i); 
            }
        }
    }
    return strs[0].substr(0, minLength); // All characters match
}

