// Give the element needed to make xor of the numbers as maximum(2^maximumBit-1) after removing from the back
// Input: nums = [2,3,4,7], maximumBit = 3
// Output: [5,2,6,5]
// Explanation: The queries are answered as follows:
// 1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
// 2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
// 3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
// 4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size(),m=pow(2,maximumBit)-1;
        vector<int> res;
        int prefix=0;
        for(int x:nums){
            prefix^=x;
        }
        for(int i=n-1;i>-1;i--){
            res.push_back(m-prefix);
            prefix^=nums[i];  //remove the last element by adding again  7^2=5 which means we removed 2 which is the last
        }
        return res;
    }
};
