// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic.
// A mechanic with a rank r can repair n cars in r * n2 minutes. You are also given an integer cars representing the total number of cars waiting in 
// the garage to be repaired.Return the minimum time taken to repair all the cars.
// Note: All the mechanics can repair the cars simultaneously.

// Example 1:
// Input: ranks = [4,2,3,1], cars = 10
// Output: 16
// Explanation: 
// - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
// - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
// - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
// - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
// It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
  
// Example 2:
// Input: ranks = [5,1,8], cars = 6
// Output: 16
// Explanation: 
// - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
// - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
// - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
  
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int maxi=*max_element(ranks.begin(),ranks.end());
        long long low=1,high=(long long)cars*cars*maxi;
        long long mid;
        while(low<high){
            mid=low+(high-low)/2;
            long long totCars=0;
            for(int r:ranks){
                totCars += floor(sqrt(mid/r));
            }
            if(totCars>=cars){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
