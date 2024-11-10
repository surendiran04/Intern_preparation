//return the size of the min subarray length which can make up the OR atleast k
// Input
// nums = [1,2,32,21] , k = 55
// Output:3

// Input: nums = [1,2,3], k = 2
// Output: 1
// Explanation:
// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:
// Input: nums = [2,1,8], k = 10
// Output: 3
// Explanation:
// The subarray [2,1,8] has OR value of 11. Hence, we return 3.

// Example 3:
// Input: nums = [1,2], k = 0
// Output: 1
  
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) { //TLE - 666/718
        int len=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=i;j<n;j++){
                ans|=nums[j];
                if(ans>=k){
                    len=min(len,j-i+1);
                    break;
                }
            }
        }
        return len==INT_MAX?-1:len;
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int len = INT_MAX;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        vector<int> bits(32,0);
        for (int r = 0; r < n; r++) {
            updateBits(bits,nums[r],1);
            while (convertBits(bits) >= k && l<=r) {
                len = min(len, r - l + 1);
                updateBits(bits,nums[l],-1);
                l++;
            }
        }
        return len == INT_MAX ? -1 : len;
    }
    void updateBits(vector<int> &bits,int n,int delta){
        for(int i=0;i<32;i++){
            if((n >> i)&1){
                bits[i]+=delta;
            }
        }
    }
    int convertBits(vector<int> &bits){
        int res=0;
        for(int i=0;i<32;i++){
            if(bits[i]!=0){
                res|=1 << i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) { //It didn't work 
        int len = INT_MAX;
        int n = nums.size();
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            ans |= nums[r];
            while (ans >= k) {
                len = min(len, r - l + 1);
                ans &= ~nums[l]; // Properly remove nums[l]'s contribution from ans
                l++;
            }
        }
        
        return len == INT_MAX ? -1 : len;
    }
};
