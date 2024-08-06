// Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
// Output: 5
// Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
// Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
// Output: 5
// Explanation: The subarray is 0 -4 3 1 0.
class Solution {  //this sum k = 0 
  public:
    int maxLen(vector<int>& arr, int n) { //brute force 
        int sum;
        int len=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==0){
                    len=max(len,j-i+1);
                }
            }
            
        }
        return len;
    }
};

class Solution { //optmised approach this works even if the array contains negative values
  public:
    int maxLen(vector<int>& arr, int n) {
        int k=0; //this sum k=0
        int sum;
        int maxlen=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            if(map.find(sum-k)!=map.end()){
                maxlen=max(maxlen,i-map[sum]);
            }
            else{
               map[sum]=i;   
             }
            
        }
        return maxlen;
    }
};
