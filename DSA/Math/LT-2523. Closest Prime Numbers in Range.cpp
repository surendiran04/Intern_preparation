// left <= num1 < num2 <= right .
// Both num1 and num2 are prime numbers.
// num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.
// Input: left = 4, right = 6
// Output: [-1,-1]
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        vector<bool> isPrime(right + 1, true);
        getPrime(right,isPrime);
        for(int i=left;i<=right;i++){
            if(isPrime[i]){
                prime.push_back(i);
            }
        }
        int n=prime.size();
        int a=-1,b=-1; 
        if(n<2){
            return {a,b};
        }
        int diff=0,minDiff=INT_MAX;
        for(int i=1;i<n;i++){
            diff=prime[i]-prime[i-1];
            if(diff<minDiff){
                minDiff=diff;
                a=prime[i-1];
                b=prime[i];
            }
        }
        return {a,b};
    }
    void getPrime(int n,vector<bool>& isPrime){   //sieve of Eratosthenes
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
    }
};
