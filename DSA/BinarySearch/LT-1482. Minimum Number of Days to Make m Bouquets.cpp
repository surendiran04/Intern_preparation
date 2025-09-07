class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {  //Got TLE
        int n=bloomDay.size();
        if(n<(long)m*k){
            return -1;
        }
        int mini=*min_element(begin(bloomDay),end(bloomDay));
        int maxi=*max_element(begin(bloomDay),end(bloomDay));
        for(int i=mini;i<=maxi;i++){                 //O(n*(maxi-mini+1))
            if(feasible(bloomDay,i,m,k)){
                return i;
            }
        }
        return -1;
    }
    bool feasible(vector<int>& bloom,int day,int m,int k){
        int n=bloom.size();
        int cnt=0,no_boq=0;
        for(int i=0;i<n;i++){
            if(bloom[i]<=day){
                cnt++;
            }else{
                no_boq+=cnt/k;
                cnt=0;
            }

            if(i==n-1){
                no_boq+=cnt/k;
            }
        }
        if(no_boq>=m){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { ///O(n*log(maxi-mini+1))
        int n=bloomDay.size();
        if(n<(long)m*k){
            return -1;
        }
        int l=*min_element(begin(bloomDay),end(bloomDay));
        int r=*max_element(begin(bloomDay),end(bloomDay));
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(feasible(bloomDay,mid,m,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool feasible(vector<int>& bloom,int day,int m,int k){
        int n=bloom.size();
        int cnt=0,no_boq=0;
        for(int i=0;i<n;i++){
            if(bloom[i]<=day){
                cnt++;
            }else{
                no_boq+=cnt/k;
                cnt=0;
            }

            if(i==n-1){
                no_boq+=cnt/k;
            }
        }
        if(no_boq>=m){
            return true;
        }
        return false;
    }
};
