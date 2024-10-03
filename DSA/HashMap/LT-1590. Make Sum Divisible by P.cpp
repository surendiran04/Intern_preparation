class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        int rem=sum%p;
        if(rem==0){
            return 0;
        }
        int subSum=0,len=999,l=0;
        for(int r=0;r<n;r++){ //since it's a subarray i came up with this soln it fails 1/3 cases arr=[6,3,5,2] p=9 output: 2 ie;[5,2]
            subSum+=nums[r];
            while(subSum>rem){ //it removes from the beginning
                subSum-=nums[l++];
            }
            if(subSum==rem){
                len=min(len,n-r-l+1);
            }
        }
        return len==999?-1:len;
    }
};
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long sum=0;
        for(int num:nums){
            sum+=num;
        }
        int rem=sum%p;
        if(rem==0){
            return 0;
        }
        unordered_map<int,int> map;
        map[0]=-1;
        long subSum=0;
        int len=n;
        for(int i=0;i<n;i++){
            subSum+=nums[i]; //prefix sum
            int cur_rem=subSum%p;
          int target=(cur_rem-rem+p)%p;  //if target is found means we found an subarray = rem
            if(map.find(target)!=map.end()){
                len=min(len,i-map[target]); 
            }
            map[cur_rem]=i;
        }
        return len==n?-1:len;
    }
};
