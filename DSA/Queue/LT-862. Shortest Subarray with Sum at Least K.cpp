// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
// If there is no such subarray, return -1.

// Example 1:
// Input: nums = [1], k = 1
// Output: 1
  
// Example 2:
// Input: nums = [1,2], k = 4
// Output: -1
  
// Example 3:
// Input: nums = [2,-1,2], k = 3
// Output: 3

// Input
// nums = [2, -1, 2, -1, 2], k = 3

// Prefix Sum:
// prefixSum = [0, 2, 1, 3, 2, 4]
  
// Deque Operations:
// Step 1: i = 0  , Current prefix sum: prefixSum[0] = 0
// Action: Add (0, 0) to the deque because it's the first element.
// Deque after step: [(0, 0)]
// Step 2: i = 1 ,Current prefix sum: prefixSum[1] = 2
// Action: No pop_back needed since the deque is increasing. Add (2, 1) to the deque.
// Deque after step: [(0, 0), (2, 1)]
// Step 3: i = 2 , Current prefix sum: prefixSum[2] = 1
// Action: pop_back: Remove (2, 1) because 1 < 2 (new prefix sum is smaller and better).Add (1, 2) to the deque.
// Deque after step: [(0, 0), (1, 2)]
// Step 4: i = 3, Current prefix sum: prefixSum[3] = 3
// Action: Check front for condition: prefixSum[3] - dq.front().first >= k 
//3 - 0 >= 3: True. Remove (0, 0) from the front and update minLength = 3 - 0 = 3.No pop_back is needed since the deque remains valid.Add (3, 3) to the deque.
// Deque after step: [(1, 2), (3, 3)]
// Step 5: i = 4, Current prefix sum: prefixSum[4] = 2
// Action: pop_back: Remove (3, 3) because 2 < 3 (new prefix sum is smaller and better). Add (2, 4) to the deque.
// Deque after step: [(1, 2), (2, 4)]
// Step 6: i = 5, Current prefix sum: prefixSum[5] = 4
// Check front for condition: prefixSum[5] - dq.front().first >= k. 4 - 1 >= 3: True. Remove (1, 2) from the front and update minLength = 5 - 2 = 3.
// No pop_back needed since the deque is increasing.Add (4, 5) to the deque.
// Deque after step: [(2, 4), (4, 5)]


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq; 
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int minLength = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            // Remove elements from deque that cannot form a valid subarray
            while (!dq.empty() && prefixSum[i] - dq.front().first >= k) {
                minLength = min(minLength, i - dq.front().second);
                dq.pop_front();
            }
            // Maintain the deque order and remove unnecessary elements
            while (!dq.empty() && dq.back().first >= prefixSum[i]) {
                dq.pop_back();
            }
            dq.emplace_back(prefixSum[i], i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
