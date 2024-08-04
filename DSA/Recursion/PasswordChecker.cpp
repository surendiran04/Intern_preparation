// Returns
// - string: Return the passwords as a single string in the order required for the password to be accepted, each separated by a space. 
//   If it is not possible to form the string, return the string WRONG PASSWORD.

// The first line contains an integer t, the total number of test cases.
// Each of the next  sets of three lines is as follows:
// - The first line of each test case contains n, the number of users with passwords.
// - The second line contains n space-separated strings, passwords[i], that represent the passwords of each user.
// - The third line contains a string, loginAttempt, which Yu must test for acceptance.

// Input:
// 3 - testcases
// 6
// because can do must we what
// wedowhatwemustbecausewecan
// 2
// hello planet
// helloworld
// 3
// ab abcd cd
// abcd
// Output:
// we do what we must because we can
// WRONG PASSWORD
// ab cd

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

bool canFormPassword(const std::vector<std::string>& words, const std::string& password, std::string& result) {
    std::unordered_map<std::string, int> wordCount;
    for (const auto& word : words) {
        wordCount[word]++;
    }

    std::string currentWord;
    for (size_t i = 0; i < password.size(); ++i) {
        currentWord += password[i];
        if (wordCount.find(currentWord) != wordCount.end() && wordCount[currentWord] > 0) {
            result += currentWord + " ";
            wordCount[currentWord]--;
            currentWord.clear();
        }
    }

    return currentWord.empty();
}

std::string validatePassword(const std::vector<std::string>& words, const std::string& password) {
    std::string result;
    if (canFormPassword(words, password, result)) {
        // Remove the trailing space
        if (!result.empty()) {
            result.pop_back();
        }
        return result;
    } else {
        return "WRONG PASSWORD";
    }
}

int main() {
    int n = 3;
    std::vector<std::string> words = {"ab", "abcd", "cd"};
    std::string password = "abcd";

    std::string result = validatePassword(words, password);

    std::cout << result << std::endl;

    return 0;
}
