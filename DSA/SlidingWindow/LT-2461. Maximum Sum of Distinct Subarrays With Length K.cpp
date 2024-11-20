// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15   [4,2,9]=15
// Input: nums = [4,4,4], k = 3
// Output: 0
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, maxSum = 0;
        int n = nums.size();
        int l = 0, r = k;
        unordered_map<int, int> map;
        for (; l < r; l++) {
            sum += nums[l];
            map[nums[l]]++;
        }
        if (map.size() == k) {
            maxSum = sum;
        }
        l=0;
        while (r < n) {
            sum -= nums[l];
            sum += nums[r];
            if (map[nums[l]] == 1) {
                map.erase(nums[l]);
            } else {
                map[nums[l]]--;
            }
            map[nums[r]]++;
            if (map.size() == k) {
                maxSum = max(sum, maxSum);
            }
            l++;
            r++;
        }
        return maxSum;
    }
};
