// Input: nums = [1,0,2,1,3]
// Output: [3,3,2,2,1]
// Explanation:
// The maximum possible bitwise OR starting at any index is 3. 
// - Starting at index 0, the shortest subarray that yields it is [1,0,2].
// - Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
// - Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
// - Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
// - Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
// Therefore, we return [3,3,2,2,1]. 
// Example 2:

// Input: nums = [1,2]
// Output: [2,1]

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,maxOR=0;
        vector<int> setBit(31,-1);
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(nums[i] & (1<<j)){
                    setBit[j]=i;
                }
            }
            int maxIdx=i;
            for(int j=0;j<31;j++){
                maxIdx=max(setBit[j],maxIdx);
            }
            res[i]=maxIdx-i+1;
        }
        return res;
    }
};
