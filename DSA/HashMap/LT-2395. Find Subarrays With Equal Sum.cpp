// Determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
// Return true if these subarrays exist, and false otherwise.
// Input: nums = [4,2,4]
// Output: true
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        if(n==2){
            return false;
        }
        int l=1;
        unordered_set<int> set; //initially used a sliding window approach which only checks for adjacent elements from front and last
        while(l<n){
            int sum=nums[l-1]+nums[l];
            if(set.count(sum)>0){
                return true;
            }else{
                set.insert(sum);
                l++;
            }
        }
        return false;
    }
};
