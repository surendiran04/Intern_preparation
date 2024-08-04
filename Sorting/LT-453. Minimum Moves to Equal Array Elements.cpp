class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        sort(nums.begin(),nums.end());
        int x=nums[0];
        for(int num:nums){
            if(num!=x){
                moves+=num-x;
            }
        }
        return moves;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        int x=INT_MAX;
        for(int n:nums){
            x=min(x,n);
        }
        for(int num:nums){
            if(num!=x){
                moves+=num-x;
            }
        }
        return moves;
    }
};
