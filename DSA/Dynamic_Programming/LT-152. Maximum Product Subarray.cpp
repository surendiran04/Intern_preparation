class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int product=1,maxProduct=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                product*=nums[j];
                maxProduct=max(maxProduct,product);
            }
            product=1;
        }
        return maxProduct;
    }
};
// nums = [3,-1,4]
// output needs to  be 4 so we are using suffix as well  
class Solution { //prefix and suffix product
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefix=1,suffix=1,maxProduct=INT_MIN;
        for(int i=0;i<n;i++){
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-1-i];
            maxProduct=max(maxProduct,max(prefix,suffix));
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
        }
        return maxProduct;
    }
};
