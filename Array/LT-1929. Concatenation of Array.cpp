class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums);  //copying intial set of elements
        // for(int num:nums){
        //     res.push_back(num);
        // }
        for(int num:nums){
            res.push_back(num);
        }
        return res;
    }
};
class Solution { //best approach
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] = ans[i + n] = nums[i];
        }
        return ans;
    }
};
