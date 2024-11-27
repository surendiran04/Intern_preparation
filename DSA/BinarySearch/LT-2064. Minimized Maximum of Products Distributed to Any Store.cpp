// we hvae to distribute m diff types of products to n stores where we can distribute atmost one product to each store.
// Return the minimum possible distribution.

// Example 1:
// Input: n = 6, quantities = [11,6]  
// Output: 3   = max(1-3,2-3,3-3,4-3,5-3,6-2)
    
// Example 2:
// Input: n = 7, quantities = [15,10,10]
// Output: 5
    
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int res=high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isFeasible(quantities,n,mid)){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;
    }
    bool isFeasible(vector<int>& products,int n,int maxShop){
        int req_shops=0;
        for(int p:products){
            req_shops+=ceil((double)p/maxShop);  //distributing by finding a mid but of it is not optimal then chnage the mid
            if(req_shops>n){
                return false;
            }
        }
        return true;
    }
};
