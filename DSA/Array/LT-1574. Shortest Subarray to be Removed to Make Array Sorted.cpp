//return the length of the shortest subaaray to make array sorted 
// Input: arr = [1,2,3,10,4,2,3,5]
// Output: 3
// Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
// Another correct solution is to remove the subarray [3,10,4].
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        while(left+1 < n && arr[left]<=arr[left+1]){
            left++;
        }
        if(left==n-1){
            return 0;  //already sorted 
        }
        int right=n-1;
        while(right>0 && arr[right-1]<=arr[right]){
            right--;
        }
        int res=min(n-left-1,right);
        int i=0,j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                res=min(res,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
