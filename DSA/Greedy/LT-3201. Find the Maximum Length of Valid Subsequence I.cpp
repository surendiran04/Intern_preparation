// A subsequence sub of nums with length x is called valid if it satisfies:
// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 4
// Explanation:
// The longest valid subsequence is [1, 2, 3, 4].
  
// Example 2:
// Input: nums = [1,2,1,1,2,1,2]
// Output: 6
// Explanation:
// The longest valid subsequence is [1, 2, 1, 2, 1, 2].

// Example 3:
// Input: nums = [1,3]
// Output: 2
// Explanation:
// The longest valid subsequence is [1, 3].

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int p=nums[0]&1;
        int cnt[3]={!p,p,1};  // there are only 3 possibilities both odds,both even and alternate
        for(int i=1;i<n;i++){
            bool z=nums[i]&1;
            cnt[z&1]++;
            if(z!=p){ //alternate parity condition
                cnt[2]++;
                p=!p;
            }
        }   
        return max({cnt[0],cnt[1],cnt[2]});
    }
};
