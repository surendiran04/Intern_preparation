class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag=false;
        bool alt=!(n & 1);
        while(n>0){
            if(!flag && n & 1){
                flag=true;
            }else if(n & 1){
                return false;
            }
            if(!(n&1)){
                flag=false;
            }
            n>>=1;
            if(alt==flag){
                return false;
            }
            alt=flag;
        }
        return true;
    }
};
