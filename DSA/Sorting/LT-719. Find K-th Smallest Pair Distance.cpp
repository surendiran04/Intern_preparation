class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int low=0,high=nums[n-1]-nums[0];
       auto countp = [&](int max_distance){
         int count=0,j=0;
         for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=max_distance) j++;
            count += j-i-1;
         }
         return count;
       };
       while(low<high){
          int mid=low+(high-low)/2;
          if(countp(mid)<k){
            low=mid+1;
          }else{
            high=mid;
          }
       }
       return low;
    }
};
