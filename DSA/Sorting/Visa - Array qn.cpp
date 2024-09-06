// Given two arrays named a and b of size n and m respectively. Find the maximum number 
// of pairs (a[i], b[j]) such that a[i]>b[j], 0<=i<n and 0<=j<m. Also, an element of the array 
// can appear at-most in only one pair. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPairs(vector<int>& a, vector<int>& b) {
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, pairs = 0;
    
    // Use two pointers to find maximum number of valid pairs
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            // If a[i] > b[j], form a pair and move both pointers
            pairs++;
            i++;
            j++;
        } else {
            // If a[i] <= b[j], move the pointer i to find a larger value
            i++;
        }
    }

    return pairs;
}

int main() {
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> b1 = {1, 6, 1, 6, 1};
    cout << "Maximum Possible Pairs = " << maxPairs(a1, b1) << endl;

    vector<int> a2 = {3, 2, 3};
    vector<int> b2 = {8, 1, 2};
    cout << "Maximum Possible Pairs = " << maxPairs(a2, b2) << endl;

    return 0;
}
