//Return the array of powers whick means if a k-sized subarray is continuous(1,2,3) then stored the max element in the subaaray else -1
// Example 1:
// Input: nums = [1,2,3,4,3,2,5], k = 3
// Output: [3,4,-1,-1,-1]
// Explanation:
// There are 5 subarrays of nums of size 3:
// [1, 2, 3] with the maximum element 3.
// [2, 3, 4] with the maximum element 4.
// [3, 4, 3] whose elements are not consecutive.
// [4, 3, 2] whose elements are not sorted.
// [3, 2, 5] whose elements are not consecutive.

// Example 2:
// Input: nums = [2,2,2,2,2], k = 4
// Output: [-1,-1]

// Example 3:
// Input: nums = [3,2,3,2,3,2], k = 2
// Output: [-1,3,-1,3,-1]

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n-(k-1);i++){
            if(checkCondition(nums,i,k)){
                res.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
    bool checkCondition(vector<int>&nums,int start,int k){
        for(int i=start;i<start+k-1;i++){
            if(nums[i]!=nums[i+1]-1){
                return false;
            }
        }
        return true;
    }
};
