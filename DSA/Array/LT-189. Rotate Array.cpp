class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return;
        }
        k=k%n;
        // while(k>0){
        //     int t=nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=t;
        //     k--;
        // }
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        for(int i=0;i<n/2;i++){ // reverse(nums.begin(),nums.end());
            swap(nums[i],nums[n-i-1]);
        }
        
    }
};
