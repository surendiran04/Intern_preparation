// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return;
        }
        int l=0;
        for(int r=1;r<n;r++){
            if(nums[l]==0 && nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }else if(nums[l]!=0){
                l++;
            }
        }
    }
};
