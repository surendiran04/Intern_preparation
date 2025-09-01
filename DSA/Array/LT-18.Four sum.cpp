class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int k = n - 1; k > i + 2; k--) {
                if (k < n - 1 && nums[k] == nums[k + 1]) {
                    continue;
                }
                int j = i + 1, l = k - 1;
                while (j < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[k]});
                        j++;
                        l--;
                        while (j < l && nums[j] == nums[j - 1]) {
                            j++;
                        }
                        while (j < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    } else if (sum < target) {
                        j++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return res;
    }
};
