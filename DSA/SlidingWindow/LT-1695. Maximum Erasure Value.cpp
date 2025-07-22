// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray
//is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// Example 1:
// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].

// Example 2:
// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=0,maxSum=INT_MIN;
        unordered_map<int,int> map;
        while(r<n){
            sum+=nums[r];
            map[nums[r]]++;
            while(map[nums[r]]>1){
                sum-=nums[l];
                map[nums[l++]]--;
            }
            maxSum=max(maxSum,sum);
            cout<<maxSum<<" ";
            r++;   
        }
        return maxSum;
    }
};
