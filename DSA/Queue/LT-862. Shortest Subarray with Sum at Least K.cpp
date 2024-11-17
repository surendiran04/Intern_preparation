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
  
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq; // Pair of prefix sum and index
        vector<long long> prefixSum(n + 1, 0);

        // Compute prefix sums
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

            // Add the current prefix sum and index to the deque
            dq.emplace_back(prefixSum[i], i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
