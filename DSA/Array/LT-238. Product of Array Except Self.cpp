class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cur = 1;
        int n= nums.size();
        vector<int> ans(n,1);
        for (int i = 0; i < n; i++) {
            ans[i] = cur;
            cur *= nums[i];
        }
        cur = 1;
        for (int i = n - 1; i >= 0; i--){
            ans[i] *= cur; 
            cur *= nums[i]; 
        }
        return ans;
    }
};
