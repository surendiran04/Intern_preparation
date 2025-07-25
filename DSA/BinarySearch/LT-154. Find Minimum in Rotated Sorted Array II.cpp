//Similiar to rotated sorted array but also contains duplicates
// [1,3,3] [3,3,3,1,3],[5,1,3,3,3] , [3,3,1,3]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }
            if(nums[mid]>nums[r]){
                    l=mid+1;  
            }else{
                    r=mid;
            }
        }
        return nums[l];
    }
};
