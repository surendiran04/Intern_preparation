// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment or decrement an element of the array by 1.
// Example 1:
// Input: nums = [1,2,3]
// Output: 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// Example 2:

// Input: nums = [1,10,2,9]
// Output: 16

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int avg=accumulate(nums.begin(),nums.end(),0);
        avg/=n;
        int moves=0;
        for(int n:nums){
            moves+=abs(avg-n);
        }
        return moves;
    }
};
