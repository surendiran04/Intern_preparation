// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1))
//Example 1:
// Input: n = 3, k = 1
// Output: "0"
// Explanation: S3 is "0111001".
// The 1st bit is "0".

// Example 2:
// Input: n = 4, k = 11
// Output: "1"
// Explanation: S4 is "011100110110001".
// The 11th bit is "1".

class Solution {
public:
    char findKthBit(int n, int k) {
        // vector<string> s={"0","01","011","0111001","011100110110001"}; //getting error due to string size can't hold 2^20 size
        // if(n<5){
        //     return s[n-1][k];
        // }
        // for(int i=5;i<=n;i++){
        //     string sn=s.back()+"1";
        //     string x;
        //     for(char x1:s.back()){
        //         x=((x1=='0')?'1':'0')+x;
        //     }
        //     sn=sn+x;
        //     s.push_back(sn);
        // }
        // return s[n-1][k];
        if(n==1){
            return '0';
        }
        int len=(1<<n)-1;
        int mid=len/2+1;
        if(k==mid){
            return '1';
        }
        if(k<mid){
            return findKthBit(n-1,k);
        }

        return findKthBit(n-1,len-k+1) == '0'?'1':'0';
    }
};

class Solution {
public:
    char findKthBit(int n, int k) {
        int invert = 0;
        int len = (1 << n) - 1; // 2^n -1 
        
        while (k > 1) {
            if (k == len / 2 + 1) {
                return invert % 2 == 0 ? '1' : '0';
            } else if (k > len / 2 + 1) {
                k = len - k + 1;
                invert++;
            }
            len = len / 2;
        }
        
        return invert % 2 == 0 ? '0' : '1';
    }
};
