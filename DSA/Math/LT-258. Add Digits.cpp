// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0
 
// 1=1; 2=2; 3=3; 4=4; 5=5; 6=6; 7=7; 8=8; 9=9;
// 10=1; 11=2; 12=3; 13=4; 14=5; 15=6; 16=7; 17=8; 18=9;
// 19=1; 20=2; 21=3; 22=4; 23=5; 24=6; 25=7; 26=8; 27=9;
// ... ...
// so, we supposed that the rule is a cycle per 9 number.
// the math formulation:
// (num - 1) % 9 + 1

// note: num - 1 is to avoid k*9%9 = 0
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};
