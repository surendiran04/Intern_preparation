class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[h] >= target && target >= nums[m]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }
        return -1;
    }
};
