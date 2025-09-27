// 1. Find the count of minimum non-overlapping intervals given [start,end] time. Two slot's are considered overlapping [a,b],[c,d] a<=c and c<=b+1
//   sample inputs: [[1,4],[2,5],[7,8]] op:2  input:[[1,2],[3,4],[6,8]] here [1,2],[3,4] overlap into [1,4] so op:2
  
int minNonOverlappingSchedules(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    int count = 0;
    int currentEnd = -1;
    for (auto& it : intervals) {
        int start = it[0];
        int end = it[1];
        if (count == 0) {
            count = 1;
            currentEnd = end;
        } else {
            if (start <= currentEnd + 1) {
                currentEnd = max(currentEnd, end);
            } else {
                count++;
                currentEnd = end;
            }
        }
    }
    return count;
}

// 2. find the maximum possible score (sum of cell values) by traversing a grid (or "board") from a specific starting cell to the opposite side of the grid.
//   There are two possible starting points, and you need to find the maximum score for each path and then return the overall maximum.  
//   Start Path 1 (Top-Down): Start at row 0 and a given column p, i.e., cell (0,p). The path moves downwards towards row n−1.
//   Start Path 2 (Bottom-Up): Start at row n−1 and a given column q, i.e., cell (n−1,q). The path moves upwards towards row 0.
// board=[[9,4,7],[2,1,3],[1,4,2]] p=2 q=1
// Top-down approach starts from (0,p) which (0,2) value:7 and find the path 7+3+4=14
// Bottom-up approach starts from (n-1,1) which (2,1) value:4 and find the path 4+2+9=15 ans:15 which is max(15,14)
//  board=[[1,2,3],[4,5,6],[7,8,9]] p=1 q=0
// Top-down approach starts from (0,p) which (0,1) value:2 and find the path 2+6+9=17
// Bottom-up approach starts from (n-1,q) which (2,0) value:7 and find the path 7+5+3=15 ans:17 which is max(17,15) 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int maxPathSum(vector<vector<int>>& board, int p, int q) {
    int n = board.size();
    if (n == 0) {
        return 0;
    }
    int m = board[0].size();
    // --- DP for Path 1: Top-Down (starting at (0, p) and ending at row n-1) ---
    vector<vector<int>> dp_down = board;
    int NEG_INF = -1000000000; 

    for (int j = 0; j < m; ++j) {
        if (j != p) {
            dp_down[0][j] = NEG_INF;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int max_prev = NEG_INF;
            
            if (j > 0) {
                max_prev = max(max_prev, dp_down[i - 1][j - 1]);
            }
            max_prev = max(max_prev, dp_down[i - 1][j]);
            if (j < m - 1) {
                max_prev = max(max_prev, dp_down[i - 1][j + 1]);
            }
            
            if (max_prev == NEG_INF) {
                dp_down[i][j] = NEG_INF; // Unreachable
            } else {
                dp_down[i][j] += max_prev;
            }
        }
    }

    int max_down_sum = NEG_INF;
    for (int j = 0; j < m; ++j) {
        max_down_sum = max(max_down_sum, dp_down[n - 1][j]);
    }

    // --- DP for Path 2: Bottom-Up (starting at (n-1, q) and ending at row 0) ---
    vector<vector<int>> dp_up = board;

    for (int j = 0; j < m; ++j) {
        if (j != q) {
            dp_up[n - 1][j] = NEG_INF;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            int max_prev = NEG_INF;
            
            if (j > 0) {
                max_prev = max(max_prev, dp_up[i + 1][j - 1]);
            }
            max_prev = max(max_prev, dp_up[i + 1][j]);
            if (j < m - 1) {
                max_prev = max(max_prev, dp_up[i + 1][j + 1]);
            }
            
            if (max_prev == NEG_INF) {
                dp_up[i][j] = NEG_INF; // Unreachable
            } else {
                dp_up[i][j] += max_prev;
            }
        }
    }

    int max_up_sum = NEG_INF;
    for (int j = 0; j < m; ++j) {
        max_up_sum = max(max_up_sum, dp_up[0][j]);
    }
  
    return max(max_down_sum, max_up_sum);
}

// 3. sliding window maximum -- Interview (deque approach optimised)
https://leetcode.com/problems/sliding-window-maximum/
  
