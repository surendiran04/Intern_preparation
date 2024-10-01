// Given an array of integers arr of even length n and an integer k.We want to divide the array into exactly n / 2 pairs such that the sum of each pair 
// is divisible by k.Return true If you can find a way to do that or false otherwise
// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(int num:arr){
            int rem=(num%k+k)%k; //adding k to avoid negative indexes
            map[rem]++;
        }
        for(int num:arr){
            int rem=(num%k+k)%k;
            if(rem==0){
                if(map[rem] & 1){ //if k=5 for num=10,5 (10,5) is a pair%k 
                    return false;
                }
            }
            else if(map[rem]!=map[k-rem]){
                return false;
            }
        }
        return true;
    }
};
