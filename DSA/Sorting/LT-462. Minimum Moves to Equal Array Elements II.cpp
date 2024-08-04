class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        int moves=0;
        for(int num:nums){
            if(num!=median){
                moves+=abs(num-median);
            }
        }
        return moves;
    }
};
