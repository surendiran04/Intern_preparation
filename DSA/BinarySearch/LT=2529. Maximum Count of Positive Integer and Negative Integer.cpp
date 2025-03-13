class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstNonNegative = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int firstPositive = std::upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int neg_count = firstNonNegative;      
        int pos_count = n - firstPositive;     

        if (neg_count == 0 && pos_count == 0) {
            return 0;
        }

        return std::max(neg_count, pos_count);
    }
};
