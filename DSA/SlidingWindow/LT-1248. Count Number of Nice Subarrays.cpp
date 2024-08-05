//nice subarray means having k odd integers in the subarray - similiar to binary subarray with sum k
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return countSubArray(nums,k) - countSubArray(nums,k-1);
    }
    int countSubArray(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum+=(nums[r]%2); //consider odd as 1 and even as 0
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};
