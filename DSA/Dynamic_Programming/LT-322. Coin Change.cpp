// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Input: coins = [2], amount = 3
// Output: -1
// Example 3:
// Input: coins = [1], amount = 0
// Output: 0

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { //TLE
        int res=f(0,coins,amount);
        return (res==INT_MAX-1)?-1:res;
    }
    int f(int ind,vector<int>& arr,int t){
        if(ind>=arr.size() || t<=0){
            return (t==0)?0:INT_MAX-1;
        }
        int res=-1;
        if(arr[ind]>t){
            int notTaken=f(ind+1,arr,t);
            res=notTaken;
        }else{
            int taken=1+f(ind,arr,t-arr[ind]);
            int notTaken=f(ind+1,arr,t);
            res=min(notTaken,taken);
        }
        return res;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { //memoized approach
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int res=f(0,coins,amount,dp);
        return (res==INT_MAX-1)?-1:res;
    }
    int f(int ind,vector<int>& arr,int t,vector<vector<int>>&dp){
        if(ind>=arr.size() || t<=0){
            return (t==0)?0:INT_MAX-1;
        }
        if(dp[ind][t]!=-1){
            return dp[ind][t];
        }
        int res=-1;
        if(arr[ind]>t){
            int notTaken=f(ind+1,arr,t,dp);
            dp[ind][t]=res=notTaken;
        }else{
            int taken=1+f(ind,arr,t-arr[ind],dp);
            int notTaken=f(ind+1,arr,t,dp);
             dp[ind][t]=res=min(notTaken,taken);
        }
        return  dp[ind][t]=res;
    }
};


// coins=[1,2,3],amount=4   //amount of ways that the amount can be produced {1,1,1,1},{1,2,1},{2,2},{1,3} - 4
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size()-1;
        return f(n,coins,amount);
    }
    int f(int ind,vector<int>& arr,int t){
        if(ind==0){
            return (t%arr[0]==0);
        }
        int notTake=f(ind-1,arr,t);
        int take=0;
        if(arr[ind]<=t){
            take=f(ind,arr,t-arr[ind]);
        }
        return notTake+take;
    }
};
