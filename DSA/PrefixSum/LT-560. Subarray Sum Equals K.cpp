// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        count[0]=1;
        int currentSum=0;
        int totalSubarrays=0;
        for(auto num:nums){
            currentSum+=num;
            if(count.find(currentSum-k)!=count.end()){
                totalSubarrays+=count[currentSum-k];
            }
            count[currentSum]++;
        }
        return totalSubarrays;
    }
};
