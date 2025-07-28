// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 1
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int maxLen=0,cnt=0;
        for(int num:nums){
           if(num==maxi){
            cnt++;
           }else{
            cnt=0;
           }
           if(cnt>maxLen){
            maxLen=cnt;
           }

        }
        return maxLen;

    }
};
