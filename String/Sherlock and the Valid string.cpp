Sherlock considers a string to be valid if all characters of the string appear the same number of times. 
It is also valid if he can remove just  character at  index in the string, and the remaining 
characters will occur the same number of times.

  
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string isValid(string s) {
    unordered_map<char, int> charCount;
    unordered_map<int, int> frequencyCount;

    // Count frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Count frequency of these frequencies
    for (auto& pair : charCount) {
        frequencyCount[pair.second]++;
    }

    // If there's only one frequency, the string is valid
    if (frequencyCount.size() == 1) {
        return "YES";
    }

    // If there are two different frequencies, check further
    if (frequencyCount.size() == 2) {
        auto it = frequencyCount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        it++;
        int freq2 = it->first;
        int count2 = it->second;

        // One of the frequencies should appear only once and should be either 1
        // or its count reduced by 1 makes all frequencies the same
        if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 == 1)) || 
            (count2 == 1 && (freq2 - 1 == freq1 || freq2 == 1))) {
            return "YES";
        }
    }

    // In all other cases, the string is not valid
    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
