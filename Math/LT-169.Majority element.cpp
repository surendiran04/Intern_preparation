// The majority element is the element that appears more than ⌊n / 2⌋ times.
// Input: nums = [3,2,3]
// Output: 3
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
  
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size()/2;
        for(auto a:nums){
            map[a]++;
        }
        for (auto a : map) {
            if (a.second > n) {
                return a.first; 
            }
        }
        return 0;
    }
};
