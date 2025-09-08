// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// [10,20,30,40] k=2 then ans will be 60 [10,20,30] and [40]
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        int maxi=*max_element(begin(nums),end(nums)); 
        int l=maxi,r=sum;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int split=splits(nums,mid,n,k);
            if(split<=k){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    int splits(vector<int>& nums,int mini,int n,int k){
        int sum=0;
        int split=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]>mini){
                split++;
                sum=nums[i];
            }else{
              sum+=nums[i];
            }
        }
        return split;
    }
};
