// Example 1:
// Input: n = 3
// Output: 2
// Explanation: arr = [1, 3, 5]
// First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
// In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
// Example 2:
// Input: n = 6
// Output: 9

class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        int total=0;
        for(int i=0;i<n;i++){
            arr[i]=(2*i)+1;
            total+=arr[i];
        }
        int avg=total/n,rem=total%n;
        int op=0;
        for(int i=0;i<n;i++){
            int target=(i<n-rem)?avg:avg+1;
            if(arr[i]>target){
                op+=arr[i]-target;
            }
        }
        return op;
    }
};
//can also solved using
int ans=0;
for(int i=1;i<n;i+=2){
    ans=ans+(n-i);
}
