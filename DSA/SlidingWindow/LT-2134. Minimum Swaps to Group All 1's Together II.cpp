// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count1=0;
        for(int num:nums){
            if(num==1){
                count1++;
            }
        }
        int l=0;
        int minswap=INT_MAX;
        int count0=0;
        int n=nums.size();
        for(int r=0;r<2*n;r++){
            if(nums[r%n]==0){
                count0++;
            }
            if(r-l+1>count1){
                if(nums[l%n]==0){
                    count0--;
                } 
                l++;
            }
            if(r-l+1==count1 && count0<minswap){
                minswap=count0;
            }
        }
        return minswap;
    }
};
