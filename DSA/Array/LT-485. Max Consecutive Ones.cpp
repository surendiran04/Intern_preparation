class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0,max2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                max2=max2+1;
                max1 =max(max1,max2);
            }
            else{
                max2=0;
                }
        }
        return max1;
    }
};
