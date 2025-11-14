class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftsum=0,rightsum=0;
        for(int num:nums){
            rightsum+=num;
        }
        int n=nums.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            rightsum-=nums[i];
            res[i]=abs(leftsum-rightsum);
            leftsum+=nums[i];
        }
        return res;
    }
};
