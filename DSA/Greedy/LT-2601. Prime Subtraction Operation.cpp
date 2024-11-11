//Can we make an array strictly increasing by just subtract the prime number if not return false
// Input: nums = [4,9,6,10]
// Output: true    
//9 need to be less than 6 so we need to make 9 atleast 5 to make the array istrictly increasing 9-(6-1) = 4 atleast we need to minus a prime number bw 4 to 9 

// Input: nums = [5,8,3]
// Output: false
// 8 need to be changed to 2 so atleast we need a prime no bw 6 to 8 8-7=1 ,[5,1,3] now 5 need to be less than 1 but we can't make 5 as 0 
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                int l=nums[i]-(nums[i+1]-1);
                int h=nums[i];
                int p=getPrime(l,h);
                if(p==h){
                    return false;
                }else{
                nums[i]-=p;
                }
            }
        }
        return true;
    }
private:
      int getPrime(int l,int h){
        vector<int> primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 
            71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
            151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
            233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 
            317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
            419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 
            503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 
            607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 
            701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 
            811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 
            911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
        };
        for(int p:primes){
            if(l<=p && p<h){
                return p;
            }
        }
        return h;
      }
};
