// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in 
// lexicographical order among all possible results
// Example 1:
// Input: s = "bcabc"
// Output: "abc"
// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"
 
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string removeDuplicateLetters(const std::string& s) { 
    std::map<char, int> lastIndex;
    for (int i = 0; i < s.length(); ++i) {
        lastIndex[s[i]] = i;
    }

    std::string result = "";
    std::map<char, bool> inResult;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (inResult[c]) {
            continue;
        }
        while (!result.empty() && c < result.back() && i < lastIndex[result.back()]) {
            inResult[result.back()] = false;
            result.pop_back();
        }
        result.push_back(c);
        inResult[c] = true;
    }
    return result;
}

int main() {
    std::string input1 = "dcsccdd";
    std::string output1 = removeDuplicateLetters(input1);
    std::cout << "Input: " << input1 << ", Output: " << output1 << std::endl; // Expected: csd

    std::string input2 = "ss";
    std::string output2 = removeDuplicateLetters(input2);
    std::cout << "Input: " << input2 << ", Output: " << output2 << std::endl; // Expected: s

    std::string input3 = "bcac";
    std::string output3 = removeDuplicateLetters(input3);
    std::cout << "Input: " << input3 << ", Output: " << output3 << std::endl; // Expected: bac

    std::string input4 = "abddccd";
    std::string output4 = removeDuplicateLetters(input4);
    std::cout << "Input: " << input4 << ", Output: " << output4 << std::endl; // Expected: abcd

    return 0;
}
