class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,h=n;
        int mid;
        int ans=INT_MAX;
        while(l<=h){
             mid=l+(h-l)/2;
            if(isBadVersion(mid)){ //isBadVersion give true or false 
                 ans=(ans>mid)?mid:ans;
                 h=mid-1; //we need to find the lowest bad version
            }else{
                l=mid+1;
            }
        }
        return ans; 
    }
};
