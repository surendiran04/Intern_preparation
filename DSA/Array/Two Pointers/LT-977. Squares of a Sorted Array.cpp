class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int l=0,r=n-1;
        int i=n-1;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                res[i--]=nums[l]*nums[l]; // we can only put the num at end 
                l++;
            }else{
                res[i--]=nums[r]*nums[r];
                r--;
            }
        }
        return res;
    }
};
