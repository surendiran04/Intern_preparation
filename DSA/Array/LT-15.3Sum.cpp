class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1; 
            int k=nums.size()-1; 
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++; //this condition reduces duplicates
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum<0){
                    j++;
                }
                else{  //(sum>0)
                    k--; //if the number is greater than target then k must be larger we can reduce k
                }
            }
        }
        return result;
    }
};
