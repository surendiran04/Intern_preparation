class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(begin(weights),end(weights));  //at max d=n at that time atleast need to ship max weight's element
        int r=accumulate(begin(weights),end(weights),0);
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(feasible(weights,days,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool feasible(vector<int>& weights,int days,int cap){
        int n=weights.size();
        int no_days=0,sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>cap){ //to handle the last index
                no_days+=1;
                sum=weights[i];
            }else{                //sum+weights[i]<=cap
                sum+=weights[i];
            }
        }
        return no_days<=days;
    }
};
