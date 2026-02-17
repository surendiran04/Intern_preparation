class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int maxlen=INT_MIN;
        int i=0;
        for(int j=0;j<n;j++){
            while(nums[j]>(long long)nums[i]*k){ //when the condition becomes true, the window shrinks
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return n-maxlen;
    }
};
