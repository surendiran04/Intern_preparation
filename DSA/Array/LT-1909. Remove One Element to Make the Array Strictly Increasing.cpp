class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isSorted(nums,i)){ //picking 1 element and checking whether the array can sorted
                return true;
            }
        }
        return false;
    }
    bool isSorted(vector<int>& nums,int ind){
        int n=nums.size();
        int last=0;
        for(int i=0;i<n;i++){
            if(i==ind){
                continue;
            }
            if(nums[i]<=last){
                return false;
            }
            last=nums[i];
        }
        return true;
    }
};

class Solution{
public:
    bool canBeIncreasing(vector<int>& nums){ //optimised
        int count = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] <= nums[i-1]){
                if(count == 1) return false;
                count++;
                if(i > 1 && nums[i] <= nums[i-2]){
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};
