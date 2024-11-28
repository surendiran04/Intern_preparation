// Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// Example 1:
// Input: n = 3
// Output: 3

// Example 2:
// Input: n = 11
// Output: 0

class Solution {
public:
    int findNthDigit(int n) {
        long long digit=9;
        int first=1,length=1;
        while(n>digit*length){
            n=n-digit*length;
            length++;
            first*=10;
            digit*=10;
        }
        first+=(n-1)/length;
        string s=to_string(first);
        return s[(n-1)%length]-'0';
    }
};

class Solution { //solved 36/71 got TLE
public:
    int findNthDigit(int n) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        return s[n-1]-'0';
    }
};
