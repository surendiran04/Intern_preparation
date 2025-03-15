// You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
// Input: nums = [2,3,5,9], k = 2
// Output: 5
// Explanation: 
// There are three ways to rob at least 2 houses:
// - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
// - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
// - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
// Therefore, we return min(5, 9, 9) = 5.
// Input: nums = [2,7,9,3,1], k = 2
// Output: 2
// Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mini=1,maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int house;
        while(mini<maxi){
            int mid=(maxi+mini)/2;
            house=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    i++;
                    house++;
                }
            }
            if(house>=k){
                maxi=mid;
            }else{
                mini=mid+1;
            }
        }
        return mini;
    }
};
