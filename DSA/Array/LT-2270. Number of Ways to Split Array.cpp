// count the no of splits in the array, the split is nothing but the left sum needs to be greater than the right element sum at a certail index there always needs to
// be atleast 1 element on the right so max split may be (n-1) 
// Input: nums = [10,4,-8,7]
// Output: 2
// at index 0 and 1 the left sum is greater than right sum so there are 2 splits
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix; //here the prefix array is not needed since the whole right sum is taken part here so just with 2 variables we do it
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        int split=0;
        for(int i=0;i<n-1;i++){
            if(prefix[i]>=prefix[n-1]-prefix[i]){
                split++;
            }
        }
        return split;
    }
};
