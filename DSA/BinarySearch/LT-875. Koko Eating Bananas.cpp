// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4
  
// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l=1,h=*max_element(piles.begin(),piles.end());
        while(l<h){
            int mid=l+(h-l)/2;
            if(check(piles,hr,mid)){
                h=mid;    //mid is right so we want min so used h=mid
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    bool check(vector<int>&piles,int hr,int k){
        int hour=0;
        for(int p:piles){
            hour += (p + k - 1) / k;  // ceil((float)p/k) and (p + k - 1) / k
        }
        cout<<";"<<hour<<"-"<<k<<endl;
        return hour<=hr;
    }
};
