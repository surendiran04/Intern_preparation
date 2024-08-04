Return the minimum difference between the largest and smallest value of nums after performing at most three moves.
Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

-------Approach------------
// Sort the array nums.
// If the size of the array n is less than or equal to 4, return 0 since we can remove all elements to get an empty array which results in a difference of 0.
// Calculate the minimum difference by removing elements in these combinations:
// Remove the last 3 elements.
// Remove the first 3 elements.
// Remove the first 1 and last 2 elements.
// Remove the first 2 and last 1 elements.

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int minVal=INT_MAX;
        minVal = min(minVal, nums[n-4] - nums[0]);
        minVal = min(minVal, nums[n-1] - nums[3]);
        minVal = min(minVal, nums[n-2] - nums[2]);
        minVal = min(minVal, nums[n-3] - nums[1]);

        return minVal;
    }
};

class Solution { //best approach
public:
    int minDifference(vector<int>& nums) {
       if (nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return min({
            nums[nums.size() - 4] - nums[0],
            nums[nums.size() - 1] - nums[3],
            nums[nums.size() - 3] - nums[1],
            nums[nums.size() - 2] - nums[2]
        });
    }
};
