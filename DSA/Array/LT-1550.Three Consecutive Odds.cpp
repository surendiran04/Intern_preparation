//if the array consists of three consecutive odd numbers then return true else false
class Solution { //beats 60%
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int n:arr){
            if(n&1){
                count++;
            }
            else{
                count=0;
            }
            if(count==3){
                return true;
            }
        }
        return false;
    }
};
class Solution { //beats 100%
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int n:arr){
            (n&1)?(count++):(count=0);  //ternary operator
            if(count==3){
                return true;
            }
        }
        return false;
    }
};
//sliding window approach
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int window = 0;
        for (int i = 0; i < 3 && i < arr.size(); i++) { //intial window
            window += arr[i] % 2;
        }
        if (window == 3) {
            return true;
        }
        for (int i = 3; i < arr.size(); i++) {
            window += arr[i] % 2;
            window -= arr[i - 3] % 2;
            if (window == 3) {
                return true;
            }
        }
        return false;
    }
};
