// You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. 
//Each child can be allocated candies from only one pile of candies and some piles of candies may go unused. Return the maximum number of candies 
//each child can get.
// Input: candies = [5,8,6], k = 3
// Output: 5
// Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1.
//We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. 
// It can be proven that each child cannot receive more than 5 candies.
// Input: candies = [2,5], k = 11
// Output: 0
// input:4,7,5 , k=4
//op:3 
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkMaxCandies(candies,mid,k)){
                res=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return res;
    }
    bool checkMaxCandies(vector<int>&candies,int mid,long long k){
        long long count=0;
        for(int c:candies){
                count+=c/mid;
            if(count>=k){
                return true;
            }
        }
        return false;
    }
};
