// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Example 1:
// Input: nums = [3,2,3]
// Output: [3]
// Example 2:
// Input: nums = [1]
// Output: [1]
// Example 3:
// Input: nums = [1,2]
// Output: [1,2]
  
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<2){
            return nums;
        }
        int n=nums.size()/3;
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        vector<int> res;
        for(auto x:map){
            if(x.second>n){
                res.push_back(x.first);
            }
        }
        return res;
    }
};
