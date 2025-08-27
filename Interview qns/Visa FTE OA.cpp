// 1. Count the no of readings that are power of K
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPowerOfK(long long num, long long k) {
    if (num < 1 || k <= 0 || k == 1) {
        return (k == 1 && num == 1); 
    }
    
    double power = log((double)num) / log((double)k);
    return fabs(power - round(power)) < 1e-10; 
}

int countPowersOfK(const vector<long long>& readings, long long k) {
    int count = 0;
    for (long long num : readings) {
        if (isPowerOfK(num, k)) count++;
    }
    return count;
}

int main() {
    vector<long long> readings1 = {2, 4, 7, 8, 16, 32, 120};
    long long k1 = 2;
    cout << "Count for example 1: " << countPowersOfK(readings1, k1) << endl;

    vector<long long> readings2 = {10201, 101, 1030301, 101, 101};
    long long k2 = 101;
    cout << "Count for example 2: " << countPowersOfK(readings2, k2) << endl;

    return 0;
}

// 2. Count the no of cycles - resource conversion problem
// resources = {"A", "P", "P", "P"}; conversionRate = 3
// Start: A=1, P=3
// Step 1: Convert 3 P → A → A=2, P=0 (cycles=1)
// Step 2: Convert 1 A → P → A=1, P=1 (cycles=2)
// Step 3: Convert 1 A → P → A=0, P=2 (cycles=3)
// Step 4: Stop (not enough P and no A).
// Answer = 3 cycles

int solution(std::vector<std::string> resources, int conversionRate) {
    int cycles = 0;
    int a_count = 0;
    int p_count = 0;

    // Count 'A' and 'P'
    for (const auto& resource : resources) {
        if (resource == "A") {
            a_count++;
        } else if (resource == "P") {
            p_count++;
        }
    }

    while (true) {
        // Option 1: Convert 'P's → 'A'
        if (p_count >= conversionRate) {
            p_count -= conversionRate;
            a_count++;
            cycles++;
        } 
        // Option 2: Convert one 'A' → one 'P'
        else if (a_count >= 1) {
            a_count--;
            p_count++;
            cycles++;
        } 
        // Stop
        else {
            break;
        }
    }

    return cycles;
}


// 3. Align the paragraph properly with a border and words aligned in the center
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<vector<string>> &paragraphs, int width) {
    vector<string> lines;

    // Step 1: Build raw lines without alignment
    for (auto &para : paragraphs) {
        string curr = "";
        for (auto &word : para) {
            if (curr.empty()) {
                curr = word;
            } else {
                if ((int)curr.size() + 1 + (int)word.size() <= width) {
                    curr += " " + word;
                } else {
                    lines.push_back(curr);
                    curr = word;
                }
            }
        }
        if (!curr.empty()) lines.push_back(curr);
    }

    // Step 2: Center align each line
    for (auto &line : lines) {
        int spaces = width - line.size();
        int left = spaces / 2;
        int right = spaces - left;
        line = string(left, ' ') + line + string(right, ' ');
    }

    // Step 3: Add border
    vector<string> result;
    string border(width + 2, '*');
    result.push_back(border);
    for (auto &line : lines) {
        result.push_back("*"+line+"*");
    }
    result.push_back(border);

    return result;
}

int main() {
    vector<vector<string>> paragraphs = {
        {"hello", "world"},
        {"How", "areYou", "doing"},
        {"Please", "look", "and", "align", "to", "center"}
    };
    int width = 16;

    vector<string> formatted = solution(paragraphs, width);
    for (auto &line : formatted) {
        cout << line << "\n";
    }
    return 0;
}

// 4. Kind array operation problem solve queries 
// 1-> represent count pairs (Similiar to 2 sum)
// 0-> change the value of the index to the newval

// primary   = {1, 2, 3}
// secondary = {3, 4}
// operations = {
//     {1, 5},     // query: count pairs with sum=5
//     {0, 1, 2},  // update: secondary[1]=2
//     {1, 4}      // query: count pairs with sum=4
// }
// op: [2, 2]
std::vector<int> solution(
    std::vector<long long>& primary,
    std::vector<long long>& secondary,
    std::vector<std::vector<long long>>& operations
) {
    std::vector<int> ans;
    std::unordered_map<long long, int> freq;

    // Build frequency map from secondary
    for (long long num : secondary) {
        freq[num]++;
    }

    for (const auto& op : operations) {
        if (op[0] == 0) {
            // update: secondary[idx] = newValue
            long long idx = op[1];
            if (idx >= secondary.size()) continue;

            long long oldValue = secondary[idx];
            long long newValue = op[2];

            freq[oldValue]--;
            if (freq[oldValue] == 0) {
                freq.erase(oldValue);
            }
            secondary[idx] = newValue;
            freq[newValue]++;
        }
        else if (op[0] == 1) {
            // query: count pairs (x in primary, y in secondary) where x+y=target
            long long target = op[1];
            long long countPairs = 0;
            for (long long x : primary) {
                long long need = target - x;
                if (freq.count(need)) {
                    countPairs += freq[need];
                }
            }
            ans.push_back(static_cast<int>(countPairs));
        }
    }

    return ans;
}
