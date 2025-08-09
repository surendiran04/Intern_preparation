// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int profit=0,buy=nums[0];
        for(int i:nums){
            if(i-buy>0){ //sell if there is a immediate rise
                profit+=i-buy;
            }
            buy=i;
        }
        return profit;
    }
};
