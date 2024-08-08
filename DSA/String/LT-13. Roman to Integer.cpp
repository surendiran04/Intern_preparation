// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// Example 1:
// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:
// Input: s = "MCMXCIV"
// Output: 1994            In this case we can found out that C<M so it became 1000-100=900
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]<map[s[i+1]]){
                sum-=map[s[i]];
            }
            else{
                sum+=map[s[i]];
            }
           
        }
        return sum;
    }
};
