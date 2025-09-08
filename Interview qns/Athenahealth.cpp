// Smallest length substring with exactly k ones.
// If multiple substrings have the same length, choose the lexicographically smallest.
// So "1111" would be chosen over "0000111001" because even though "0000111001" is lexicographically smaller, "1111" is shorter.
//Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/
#include <bits/stdc++.h>
using namespace std;

string smallestSubstringWithKOnes(const string &s, int k) { 
    int n = s.size();
    string ans = "";
    int countOnes = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        if (s[right] == '1') countOnes++;

        // shrink window until at most k ones
        while (countOnes > k && left <= right) {
            if (s[left] == '1') countOnes--;
            left++;
        }

        // valid substring if exactly k ones
        if (countOnes == k) {
            string candidate = s.substr(left, right - left + 1);

            if (ans.empty() || candidate.size() < ans.size() ||
               (candidate.size() == ans.size() && candidate < ans)) {
                ans = candidate;
            }
        }
    }

    return ans.empty() ? "-1" : ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << smallestSubstringWithKOnes(s, k) << endl;
    return 0;
}
