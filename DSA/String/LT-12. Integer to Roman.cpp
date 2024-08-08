// Seven different symbols represent Roman numerals with the following values:
// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
// Input: num = 3749
// Output: "MMMDCCXLIX"
// Input: num = 58
// Output: "LVIII"
// Input: num = 1994
// Output: "MCMXCIV"

class Solution {  //  T(n) = O(1)
public:
    string intToRoman(int num) { //since in the qn it's said that the num will be less 3999
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
class Solution {    //  T(n) = O(1)   because the maximum number of operations performed is fixed and doesn't grow with the size of the input number
public:
     string intToRoman(int num){ //Subtracting the number and adding it's possibility
        int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i =0;
        string str=""; 
        while (num>0){
            if (num>=n[i]){
                str=str+s[i];
                num-=n[i];
            } else{
                i++;
            }
        }
        return str;
    }
};
