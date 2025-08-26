// A segment is a group of continuous houses. For example, the houses {1, 2, 3} form one segment.
// You are given a list of house numbers and queries. In each query, a house is removed, and you must determine how the number of segments changes after each removal.
// Example Walkthrough:
// Given:

// Houses: {1, 2, 3, 6, 7, 9}
// Queries (houses to remove in order): {6, 3, 7, 2, 9, 1}
// Initially, the houses can be viewed as divided into segments based on continuity:

// Segments: {1, 2, 3}, {6, 7}, and {9} → There are 3 segments.
// Now, the program will process each query (house removal) and adjust the number of segments accordingly.

// Remove house 6:
// Houses left: {1, 2, 3, 7, 9}
// New Segments: {1, 2, 3}, {7}, {9} → Number of segments remains 3.
// Remove house 3:
// Houses left: {1, 2, 7, 9}
// New Segments: {1, 2}, {7}, {9} → Still 3 segments.
// Remove house 7:
// Houses left: {1, 2, 9}
// New Segments: {1, 2}, {9} → Now only 2 segments.
// Remove house 2:
// Houses left: {1, 9}
// New Segments: {1}, {9} → Still 2 segments.
// Remove house 9:
// Houses left: {1}
// New Segments: {1} → Only 1 segment.
// Remove house 1:
// Houses left: {}
// No houses left → 0 segments.
// The expected output after processing each query is:

// Copy code
// 3 3 2 2 1 0
// Code Explanation
// The provided code handles this problem in a step-by-step manner:

// 1. Sorting the Houses
// cpp
// Copy code
// sort(houses.begin(), houses.end());
// This ensures that the houses are in ascending order so that contiguous segments can be easily identified.

// 2. Counting Initial Segments
// cpp
// Copy code
// int segments = 1;
// for (int i = 1; i < houses.size(); ++i) {
//     if (houses[i] != houses[i - 1] + 1) {
//         segments++;  // New gap between houses, meaning a new segment
//     }
// }
// This loop goes through the sorted list of houses and counts how many initial continuous segments exist. If two adjacent houses are not consecutive, a new segment is counted.

// 3. Processing Queries
// cpp
// Copy code
// for (int query : queries) {
//     auto it = houseSet.find(query);
    
//     bool leftNeighborExists = (it != houseSet.begin()) && (*prev(it) == query - 1);
//     bool rightNeighborExists = (next(it) != houseSet.end()) && (*next(it) == query + 1);
    
//     if (leftNeighborExists && rightNeighborExists) {
//         segments++;  // Removing query house merges two segments
//     } else if (!leftNeighborExists && !rightNeighborExists) {
//         segments--;  // Removing query house creates a new gap (splitting a segment)
//     }
    
//     houseSet.erase(it);  // Remove the house from the set
//     result.push_back(segments);  // Store the current segment count
// }
// This part handles the core logic of adjusting the number of segments as houses are removed:

// leftNeighborExists: Checks if the house to the left of the current house (query - 1) exists in the set and is contiguous.
// rightNeighborExists: Checks if the house to the right of the current house (query + 1) exists and is contiguous.
// Update logic:

// If both neighbors exist, removing the house merges two segments, so the segment count is incremented.
// If neither neighbor exists, removing the house creates a gap (splits a segment), so the segment count is decremented.
// The house is then removed from the set, and the current segment count is stored in the result vector.

#include <iostream>
#include <vector>
#include <set>
#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> houses, vector<int> queries) {
    sort(houses.begin(), houses.end());
    set<int> houseSet(houses.begin(), houses.end());
    int segments = 1;  // Initially, there is at least one segment
    for (int i = 1; i < houses.size(); ++i) {
        if (houses[i] != houses[i - 1] + 1) {
            segments++;  // New gap
        }
    }
	vector<int> result;
    for (int query : queries) {
        auto it = houseSet.find(query);
        
        bool leftNeighborExists = (it != houseSet.begin()) && (*prev(it) == query - 1);
        bool rightNeighborExists = (next(it) != houseSet.end()) && (*next(it) == query + 1);       
        if (leftNeighborExists && rightNeighborExists) {
            segments++;
        } else if (!leftNeighborExists && !rightNeighborExists) {
            segments--;
        }
        houseSet.erase(it);
        result.push_back(segments);
    }

    return result;
}

int main() {
    vector<int> houses = {1, 2, 3, 6, 7, 9};
    vector<int> queries = {6, 3, 7, 2, 9, 1};
    
    vector<int> result = solution(houses, queries);

    for (int num_segments : result) {
        cout << num_segments << " ";
    }
    cout << endl;

    return 0;
}

//rating qn given a initial rating then a array of ratings add those ratings to the array then return the level upon the final rating "beginner","Intermediate",
//"pro","advanced"

//["Insert code","backsapce","Undo"]   output:["code","cod","code"]
//used to stack to keep track of previous states for doing undo and operation
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> queries = {"Insert code", "Backspace", "Undo"};
    string text = "";
    stack<pair<string,string>> history;  // {opType, value}
    vector<string> result;

    for (auto &q : queries) {
        if (q.rfind("Insert",0) == 0) {
            string word = q.substr(7); // after "Insert "
            text += word;
            history.push({"Insert", word});
        }
        else if (q == "Backspace") {
            if (!text.empty()) {
                char deleted = text.back();
                text.pop_back();
                history.push({"Backspace", string(1,deleted)});
            }
        }
        else if (q == "Undo") {
            if (!history.empty()) {
                auto [op,val] = history.top();
                history.pop();
                if (op == "Insert") {
                    text.erase(text.size() - val.size()); // remove inserted part
                } else if (op == "Backspace") {
                    text.push_back(val[0]); // restore deleted char
                }
            }
        }
        result.push_back(text);
    }

    // Print output
    cout << "[";
    for (int i=0;i<result.size();i++) {
        cout << "\"" << result[i] << "\"";
        if (i+1<result.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}

//count the interesting strings since an interesting is considered as it should have atleast any one of the charcater repeated exactly n times
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isInteresting(const string& word, int n) {
    int len = word.length();
    for (int i = 0; i <= len - n; ++i) {
        bool valid = true;
        char repeatedChar = word[i];
        
        for (int j = i; j < i + n; ++j) {
            if (word[j] != repeatedChar) {
                valid = false;
                break;
            }
        }
        
        if (!valid) continue;

        if (i > 0 && word[i - 1] == repeatedChar) continue;
        
        if (i + n < len && word[i + n] == repeatedChar) continue;
        
        return true;
    }
    return false;
}

int countInterestingWords(const vector<string>& words, int n) {
    int count = 0;
    for (const string& word : words) {
        if (isInteresting(word, n)) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<string> words = {"abc", "abaaaccct", "abaaaa", "aaaaaba"}; //here the "abaaaccct is the i=only interesting string"
    int n = 3;
    
    int result = countInterestingWords(words, n);
    cout << "Number of interesting words: " << result << endl; //1
    
    return 0;
}
