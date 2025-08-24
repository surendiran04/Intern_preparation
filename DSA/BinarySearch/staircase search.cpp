#include <bits/stdc++.h>
using namespace std;
// m = 1000, n = 1000
// Binary Search: 1000 * log₂(1000) ≈ 10000 ops
// Staircase Search: 2000 ops (faster)

// m = 1, n = 1000000
// Binary Search: log₂(1,000,000) ≈ 20 ops
// Staircase Search: 1 + 1000000 ≈ 10^6 ops (much slower)

// ✅ So, choose based on dimensions:
// Tall matrix (more rows) → Staircase (O(m+n)).
// Wide matrix (fewer rows, many columns) → Row-wise Binary Search (O(m log n)).

bool searchMatrix(vector<vector<int>>& matrix, int target) { //O(m + n)
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0, j = n - 1;  // start from top-right
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) j--;  // move left
        else i++;  // move down
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10,13,14,17}
    };
    int target = 14;
    cout << (searchMatrix(mat, target) ? "Found" : "Not Found") << endl;
    return 0;
}
