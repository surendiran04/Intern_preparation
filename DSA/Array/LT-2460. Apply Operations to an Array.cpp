// If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
// After performing all the operations, shift all the 0's to the end of the array.
// Input: nums = [1,2,2,1,1,0]
// Output: [1,4,2,0,0,0]
//   Input: nums = [0,1]
// Output: [1,0]

//Initially, nums[i] == nums[i + 1] , nums[i]*=2, then move zeros to the last
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int> res(n,0);
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                res[j++]=nums[i];
            }
        }
        return res;
    }
};
