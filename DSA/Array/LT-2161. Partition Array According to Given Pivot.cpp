// Arrange the elements acc to pivot
// Example 1:
// Input: nums = [9,12,5,10,14,3,10], pivot = 10
// Output: [9,5,3,10,10,12,14]

// Example 2:
// Input: nums = [-3,4,3,2], pivot = 2
// Output: [-3,2,4,3]
  
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        for(int n:nums){
            if(n<pivot){
                res.push_back(n);
            }
        }
        for(int n:nums){
             if(n==pivot){
                res.push_back(n);
            }
        }
        for(int n:nums){
             if(n>pivot){
                res.push_back(n);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) { //optimal One - two pointers
        vector<int> ans(nums.size());
        int lessI = 0;
        int greaterI = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI) {
            ans[lessI] = pivot;
            lessI++;
        }
        return ans;
    }
};
