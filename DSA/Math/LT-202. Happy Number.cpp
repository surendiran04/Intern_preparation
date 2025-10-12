unordered_set<int> unique;
while (n != 1) {   //using set to find out the loop if the number prev exists or not uses extra space and got tle
    if (unique.count(n)) return false;
    n = calcDigitSquare(n);
}
return true;

class Solution {
public:
    bool isHappy(int n) { //log(n) Time complexity
        int slow=n,fast=n;
        do{
            slow=calcDigitSquare(slow);
            fast=calcDigitSquare(calcDigitSquare(fast));
        }while(slow!=fast);
        if(slow==1)
            return true;
        return false;
    }
    int calcDigitSquare(int n){
        int sum=0,rem=0;
        while(n>0){
            rem=n%10;
            sum+=rem*rem;
            n/=10;
        }
        return sum;
    }
};
