// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=prices[0];
        for(auto sell:prices){
            if(sell>buy){
                profit=(profit>(sell-buy)?profit:(sell-buy));
            }
            else{
                buy=sell;
            }
        }
        return profit;
    }
};
