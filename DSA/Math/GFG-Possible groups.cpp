//Count the pairs of grp 2 and grp3 that the sum of elements in the grp divisible by 3
//arr={3,2,7,6,9}
// ans=8
// Groups of two are: {3, 6}, {3, 9}, {9, 6}, {7, 2}. Groups of three are: {3, 7, 2}, {7, 2, 6}, {7, 2, 9}, {3, 6, 9}.  
// count the 3 types of remainders that can beformed 0,1,2
 
class Solution {
  public:
    long long ncr(long long n,int r){
        if(r==2){
            return n*(n-1)/2;
        }else if(r==3){
            return n*(n-2)*(n-1)/6;
        }
        return 0;
    }
    long long findgroups(vector<int> &arr) {
        // Your code goes here.
        int n=arr.size();
        long long c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]%3==0){
                c0++;
            }else if(arr[i]%3==1){
                c1++;
            }else{
                c2++;
            }
        }
        long long ans=0;
        ans+=c1*c2;     //all the posibilies
        ans+=ncr(c0,2); //combination in that pairs
        ans+=ncr(c0,3);
        ans+=ncr(c1,3);
        ans+=ncr(c2,3);
        ans+=c0*c1*c2;
        return ans;
    }
};
