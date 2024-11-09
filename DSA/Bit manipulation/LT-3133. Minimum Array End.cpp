//The final answer need to have 1 extra set bit than the x and the minimum possible is the answer
// Input: n = 3, x = 4
// Output: 6
// Explanation:
// nums can be [4,5,6] and its last element is 6.
// Input: n = 2, x = 7
// Output: 15
  
class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        n--;
        while(n--){
            ans=(ans+1)|x;
        }
        return ans;
    }
};
