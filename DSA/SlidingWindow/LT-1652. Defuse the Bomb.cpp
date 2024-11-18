// If k > 0, replace the ith number with the sum of the next k numbers.
// If k < 0, replace the ith number with the sum of the previous k numbers.
// If k == 0, replace the ith number with 0.
// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
// Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
// Example 1:
// Input: code = [5,7,1,4], k = 3
// Output: [12,10,16,13]
// Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

// Example 2:
// Input: code = [1,2,3,4], k = 0
// Output: [0,0,0,0]
// Explanation: When k is zero, the numbers are replaced by 0. 
  
// Example 3:
// Input: code = [2,4,9,3], k = -2
// Output: [12,5,6,13]
// Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> res(n,0);
        if(k==0){
            return res;
        }
        code.resize(2*n);
        for(int i=0;i<n;i++){
            code[i+n]=code[i];
        }
        for(int i=0;i<n && k>0;i++){
            int j=i+1,sum=0;
            while(j<=i+k){
                sum+=code[j];
                j++;
            }
            res[i]=sum;
        }
        for(int i=n+n-1;i>n-1 && k<0;i--){
            int j=i-1,sum=0;
            while(j>=i+k){
                sum+=code[j];
                j--;
            }
            res[i-n]=sum;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) return result;
        // Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        // If k < 0, the starting point will be end of the array.
        if (k < 0) {
            start = code.size() - abs(k);
            end = code.size() - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        // Scan through the code array as i moving to the right, update the
        // window sum.
        for (int i = 0; i < code.size(); i++) {
            result[i] = sum;
            sum -= code[start % code.size()];
            sum += code[(end + 1) % code.size()];
            start++;
            end++;
        }
        return result;
    }
};
