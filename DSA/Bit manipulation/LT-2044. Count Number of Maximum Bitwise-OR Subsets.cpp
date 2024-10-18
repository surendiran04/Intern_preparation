//count the no of subsets that contain the max-or of the array
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {  //T(n) - n*2^n , s(n) - O(1)
        int n=nums.size();
        int maxOR = 0;
        for (int num : nums) {
            maxOR = maxOR | num;
        }
        int count = 0;
        for (int i = 1; i < (1 << n); ++i) { //1<<n - 2^n
            int currentOR = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {          //if n=5 then 1<<j = 1 2 4 8 16 powers of 2
                    currentOR |= nums[j];
                }
            }
            if (currentOR == maxOR) {
                count++;
            } 
        }

        return count;
    }
};
