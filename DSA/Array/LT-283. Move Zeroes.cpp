// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return;
        }
        int l=0;
        for(int r=1;r<n;r++){
            if(nums[l]==0 && nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }else if(nums[l]!=0){
                l++;
            }
        }
    }
};

#include <iostream> //zeros inn the front
#include <vector>
using namespace std;  //question asked to me in the visa 2nd round interview

class Solution {
public:
    void moveZeroesToFront(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int l = n - 1;
        for (int r = n - 2; r >= 0; r--) {
            if (nums[l] == 0 && nums[r] != 0) {
                swap(nums[l], nums[r]);
                l--;
            } else if (nums[l] != 0) {
                l--;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 3, 0, 1, 12};
    Solution().moveZeroesToFront(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

