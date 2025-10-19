class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> even, odd;
        int maxlen = 0;
        for (int i = 0;i<n;++i) {
            for(int j=i;j<n;j++){
                if(nums[j] & 1){
                    odd.insert(nums[j]);
                }else{
                    even.insert(nums[j]);
                }

                if(odd.size()==even.size()){
                    maxlen = max(maxlen, j-i+1);
                }
            }   
            even.clear();
            odd.clear();
        }
        return maxlen;
    }
};
