// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
// A pair (i, j) is fair if:
// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper

//Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

// Example 2:
// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
// Output: 1
// Explanation: There is a single fair pair: (2,3).
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

private:
    long long lower_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            // If sum is less than value, add the size of window to result and
            // move to the next index.
            if (sum < value) {
                result += (right - left);
                left++;
            } else {
                // Otherwise, shift the right pointer backwards, until we get a
                // valid window.
                right--;
            }
        }
        return result;
    }
};
class Solution { //passed 47/54
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]>=lower && nums[i]+nums[j]<=upper){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
