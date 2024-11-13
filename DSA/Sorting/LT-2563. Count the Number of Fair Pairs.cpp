class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]>=lower && nums[i]+nums[j]<=upper){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
