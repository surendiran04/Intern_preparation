// Input: nums = [8,4,2,30,15]
// Output: true
// Input: nums = [3,16,8,4,2]
// Output: false
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
       vector<int> values = nums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (values[j] <= values[j + 1]) {
                    continue;
                } else {
                    if (__builtin_popcount(nums[j]) ==
                        __builtin_popcount(nums[j + 1])) {
                        // Swap the elements
                        swap(values[j], values[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int mini = 0;
        int maxi = nums[0];
        int setb = __builtin_popcount(nums[0]);

        for (int i = 1; i < nums.size(); i++){
            if (__builtin_popcount(nums[i]) != setb){
                mini = maxi;
                setb = __builtin_popcount(nums[i]);
            }
            maxi = max(maxi, nums[i]);

            if (nums[i] < mini)
            return false;
        }

        return true;
    }
};
