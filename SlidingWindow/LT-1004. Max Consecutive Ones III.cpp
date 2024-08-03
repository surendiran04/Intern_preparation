// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeros=0,maxlen=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){
                len=r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};

class Solution { //slight optimsization of while loop
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeros=0,maxlen=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){
                len=r-l+1;
                maxlen=max(maxlen,len);  
            }
              r++;
          
        }
        return maxlen;
    }
};
