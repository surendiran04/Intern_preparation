// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int len=1;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin(); //since the array is sorted we can perform a binary search and rewrite the element in temp array
                temp[ind]=nums[i];
            }
        }
        return len; //temp.size()
    }
};
