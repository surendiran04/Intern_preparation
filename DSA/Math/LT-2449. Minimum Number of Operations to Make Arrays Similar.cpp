// You are given two positive integer arrays nums and target, of the same length.
// In one operation, you can choose any two distinct indices i and j where 0 <= i, j < nums.length and:
// set nums[i] = nums[i] + 2 and
// set nums[j] = nums[j] - 2.

// Two arrays are considered to be similar if the frequency of each element is the same.
// Return the minimum number of operations required to make nums similar to target. The test cases are generated such that nums can always be similar to target.
// Example 1:
// Input: nums = [8,12,6], target = [2,14,10]
// Output: 2
// Explanation: It is possible to make nums similar to target in two operations:
// - Choose i = 0 and j = 2, nums = [10,12,4].
// - Choose i = 1 and j = 2, nums = [10,14,2].
// It can be shown that 2 is the minimum number of operations needed.

// Example 2:
// Input: nums = [1,2,5], target = [4,1,3]
// Output: 1
// Explanation: We can make nums similar to target in one operation:
// - Choose i = 1 and j = 2, nums = [1,4,3].

// Example 3:
// Input: nums = [1,1,1,1,1], target = [1,1,1,1,1]
// Output: 0
// Explanation: The array nums is already similiar to target.

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        vector<int> odd_num,odd_tar,even_num,even_tar;
        for(int i=0;i<n;i++){
            if(nums[i] & 1){
                odd_num.push_back(nums[i]);
            }else{
                even_num.push_back(nums[i]);
            }

             if(target[i] & 1){
                odd_tar.push_back(target[i]);
            }else{
                even_tar.push_back(target[i]);
            }
        }
       
        long long op=0;
        int m=odd_num.size(),p=even_tar.size();
        for(int i=0;i<m;i++){
            op+=abs(odd_num[i]-odd_tar[i])/2;
        }
        for(int i=0;i<p;i++){
            op+=abs(even_num[i]-even_tar[i])/2;
        }
        

        return (op>0)?op/2:0LL;
    }
};
