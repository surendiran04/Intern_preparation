// Input: nums = [-1,2,1,-4], target = 1       returning the sum that is closest to the target,sum is the value of any three elements in the array
// Output: 2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minSum=INT_MAX/2;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(minSum-target)){
                    minSum=sum;
                }
                if(sum<target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else{   //target=sum
                    return sum;
                }
            }
        }
        return minSum;

    }
};
