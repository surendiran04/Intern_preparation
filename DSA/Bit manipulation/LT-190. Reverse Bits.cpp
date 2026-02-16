class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits(32,0);
        for(int i=0;i<32;i++){
            if(n & 1){
                bits[i]=1;
            }
            n>>=1;
        }
        int res=0;
        for(int i=0;i<32;i++){ //bits are accessed from the back so reverse
            res<<=1;
            if(bits[i]==1){
                res|=1;
            }
        }
        return res;
    }
};
