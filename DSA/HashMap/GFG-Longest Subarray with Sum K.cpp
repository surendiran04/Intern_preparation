// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the 
// given value k. If there is no subarray with sum equal to k, return 0.

// Examples:
// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.
// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0

Explanation: No subarray with sum = 5 is present in arr[].
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int sum=0,maxlen=0;
        unordered_map<int,int>map;
        for(int r=0;r<n;r++){
            sum+=arr[r];
            if(sum==k){
                maxlen=max(maxlen,r+1);
            }
            if(map.find(sum-k)!=map.end()){
                maxlen=max(maxlen,r-map[sum-k]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=r;
            }
            
        }
        return maxlen;
    }
};
