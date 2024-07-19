// we need to find out the next greater permuation of the given numbers for eg: 1,2,3 - 1,3,2 ... 1,3,2 -2,1,3 ... 3,2,1 - 1,2,3 (as there no greater)
// Input: nums = [1,2,3]
// Output: [1,3,2]
// Input: nums = [3,2,1]
// Output: [1,2,3]
// Input: nums = [1,1,5]
// Output: [1,5,1]

//we are finding next greater element from the last if found mark the index if not then the array is int dec order(rev to find the ans) 
//else swap the greater element in theindex and reverse the remaining positions to find the next just greater permutation
  
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>index;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};
