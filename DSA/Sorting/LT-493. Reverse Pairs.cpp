Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].  // we need 2 sorted counterparts so we can count the rest of the numbers easily
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSortAndCount(nums, 0, n - 1);
    }
    long long mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        long long invCount = 0;

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            invCount += (j - (mid + 1));
        }

        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }

        return invCount;
    }

    long long mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        long long invCount = 0;

        invCount += mergeSortAndCount(nums, left, mid);
        invCount += mergeSortAndCount(nums, mid + 1, right);
        invCount += mergeAndCount(nums, left, mid, right);

        return invCount;
    }
};
