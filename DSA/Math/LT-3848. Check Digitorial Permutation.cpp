class Solution {
public:
    bool isDigitorialPermutation(int n) {
        if(check(n)){
            return true;
        }
        string s=to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0]=='0'){
              continue;
            }
           if(check(stoi(s))){
               return true;
           } 
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
    bool check(int n){
        int m=n;
        int sum=0;
        while(m>0){
            sum+=fact(m%10);
            m/=10;
        }
        return sum==n?true:false;
    }
    long long fact(int n){
        if(n<=1){
            return 1;
        }
        return n*fact(n-1);
    }
};
