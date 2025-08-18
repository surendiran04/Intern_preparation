// Input: nums = [5,2,2,4,0,6], k = 4
// Output: 5
// Explanation:
// One of the ways we can end with 5 at the top of the pile after 4 moves is as follows:
// - Step 1: Remove the topmost element = 5. The pile becomes [2,2,4,0,6].
// - Step 2: Remove the topmost element = 2. The pile becomes [2,4,0,6].
// - Step 3: Remove the topmost element = 2. The pile becomes [4,0,6].
// - Step 4: Add 5 back onto the pile. The pile becomes [5,4,0,6].
// Note that this is not the only way to end with 5 at the top of the pile. It can be shown that 5 is the largest answer possible after 4 moves.
// Example 2:

// Input: nums = [2], k = 1
// Output: -1
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return n?nums[0]:-1; 
        if(n==1) return (k&1)?-1:nums[0]; //if k is odd then we can add back the element
        if(k==1) return n>1?nums[1]:-1;   //we can only pop
        int end=min(n,k-1),maxval=0;
        maxval=*max_element(nums.begin(),nums.begin()+end); //Normal logic retaining back only maxval
        if(k<n) maxval=max(maxval,nums[k]);
        return maxval;
    }
};
