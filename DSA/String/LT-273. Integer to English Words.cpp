class Solution {
     string oneDigit[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
     string twoDigit[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
     string TenDigit[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
public:
    string numberToWords(int num){
        if(num==0){
            return "Zero";
        }
        if(num<10){
            return oneDigit[num];
        }
        if(num<100){
            return TenDigit[num/10]+" "+twoDigit[num%10];
        }
        if(num<1000){
            return oneDigit[num/100]+" "+"Hundred"+" "+TenDigit[(num%100)/10]+" "+oneDigit[num%10];
        }  
        if(num<100000){
            return twoDigit[(num/1000)%10]+" "+"Thousand"+" "+oneDigit[(num/100)%10]+" "+"Hundred"+" "+TenDigit[(num/10)%10]+" "+oneDigit[num%10];
        }
        if(num<10000000){
           return oneDigit[num/1000000]+" "+"Million"+" "+oneDigit[(num/100000)%10]+" "+"Hundred"+" "+TenDigit[(num/10000)%10]+" "+oneDigit[(num/1000)%10]+" "+"Thousand"+" "+oneDigit[(num/100)%10]+" "+"Hundred"+" "+TenDigit[(num/10)%10]+" "+oneDigit[num%10];
        }
        if(num<1000000000){
            return 
        }
        return " ";
    }
};
