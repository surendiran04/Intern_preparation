//somehow we have to reach the last index by jumping else return false
// Input: nums = [2,3,1,1,4]
// Output: true

// arr[] = [1,2,4,1,1,0,2,5] here we can jump the 5th index
// arr[]  = [1,2,3,1,1,0,2,5]  but here we can't jump
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxInd){  //if there maxInd<i which means we cannot cross the index and the index value is 0
                return false;
            }
            maxInd=max(maxInd,i+nums[i]);
        }
        return true;
    }
};
