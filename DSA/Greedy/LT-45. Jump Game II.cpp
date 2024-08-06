class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            right = max(right, nums.at(i) + i);
            if (left == i) {
                jumps++;
                left = right;
            }
        }

        return jumps;
    }
};
class Solution { //best approach
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        int r=0,l=0,jumps=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            jumps++;
            r=farthest;
        }
        return jumps;
    }
};
