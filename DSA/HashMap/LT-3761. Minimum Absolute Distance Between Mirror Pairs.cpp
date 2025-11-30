class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) { //got tle
        int n=nums.size();
        vector<int> rev;
        for(int num:nums){
            rev.push_back(reverse(num));
        }
        int mirror=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rev[i]==nums[j]){
                    mirror=min(mirror,j-i);
                }
            }
        }
        return (mirror==INT_MAX)?-1:mirror;
    }
    int reverse(int num){
        int rev=0;
        while(num>0){
            rev=rev*10+num%10;
            num/=10;
        }
        return rev;
    }
};
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int> rev;
        for(int num:nums){
            rev.push_back(reverse(num));
        }
        unordered_map<int,int> map;
        int mirror=INT_MAX;
        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                mirror=min(mirror,i-map[nums[i]]);
            }
            map[rev[i]]=i;
        }
        return (mirror==INT_MAX)?-1:mirror;
    }
    int reverse(int num){
        int rev=0;
        while(num>0){
            rev=rev*10+num%10;
            num/=10;
        }
        return rev;
    }
};
