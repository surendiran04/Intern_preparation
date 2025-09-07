// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { // Brute force
        int n=arr.size();
        int maxi=arr[n-1];
        int missing=maxi-n;
        if(k>missing){
            return maxi+k-missing;
        }
        int cnt=0;
        for(int i=1;i<maxi;i++){
            if(search(arr,i)==false){
                cnt++;
            }
            if(k==cnt){
                return i;
            }
        }
        return 0;
    }
    bool search(vector<int>&num,int t){
        int l=0,r=num.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(num[mid]==t){
                return true;
            }else if(num[mid]<t){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            int missing=arr[mid]-(mid+1);  // element - position gives the missing cnt
            if(missing<k){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l+k;
    }
};
