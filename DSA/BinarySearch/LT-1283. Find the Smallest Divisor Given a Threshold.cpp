class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(begin(nums),end(nums));
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(feasible(nums,threshold,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool feasible(vector<int>& num,int th,int div){
        int sum=0;
        for(int n:num){
            sum+=ceil((double)n/div);
        }
        return sum<=th;
    }
};
