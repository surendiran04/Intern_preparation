class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int res=high;
        float sum=0;
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
            req_shops+=ceil((double)p/maxShop);
            if(req_shops>n){
                return false;
            }
        }
        return true;
    }
};
