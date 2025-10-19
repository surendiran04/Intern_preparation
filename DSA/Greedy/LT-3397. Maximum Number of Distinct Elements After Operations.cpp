class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int curr=INT_MIN,cnt=0;
        for(int num:nums){
            curr=max(curr,num-k); //taking as min as possible and tring to assign the next smallest number in the range
            if(curr<=num+k){
                cnt++;
                curr++;
            }
        }
        return cnt;
    }
};
