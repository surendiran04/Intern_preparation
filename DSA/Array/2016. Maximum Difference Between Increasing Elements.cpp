// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid
// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].
// Input: nums = [1,5,2,10]
// Output: 9
  
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff=0;
        int min=nums[0];
        for(int i=1;i<nums.size();i++){
            if(min>nums[i]){
                min=nums[i];
            }
            diff=max(diff,nums[i]-min);
        }
        return (diff==0)?-1:diff;
    }
};
