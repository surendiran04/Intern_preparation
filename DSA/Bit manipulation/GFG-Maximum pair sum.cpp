//Sum of 2 distinct numbers in an array that has a xth bit as distinct if no such pair retun -1
// arr=[1,9,5,23,12] x=3,n=5 output=32 (9+23) 9-1001,23-10111
class Solution {
  public:
    long long maxSum(int n, int x, vector<int> &arr) {
        long long maxi=0;
        int num=0;
        maxi=*max_element(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(maxi!=arr[i] && getnthBit(maxi,x)!=getnthBit(arr[i],x)){
                num=max(num,arr[i]);
            }
        }
        return (num==0)?-1:maxi+num;
        
    }
    int getnthBit(int num,int n){
        return (num >> (n-1)) & 1;
    }
};
