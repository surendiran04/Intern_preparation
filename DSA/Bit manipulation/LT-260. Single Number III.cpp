class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return nums;
        }
        int xr=0;
        for(int num:nums){
            xr^=num;
        }
        int setbit=0;
        while(1){
            if(xr & 1 << setbit) break; //left shift - << 
            setbit++;
        }
        int num1=0,num2=0;
        for(int num:nums){ //grping the number into 2 categories 
            if(num & 1<<setbit) num1^=num;
            else num2^=num;
        }
        return {num1,num2};
    }
};
