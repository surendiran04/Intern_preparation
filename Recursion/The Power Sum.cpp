Find the number of ways that a given integer,X , can be expressed as the sum of the  powers of unique,Nth natural number
SampleInput:
Input: 10,2
Output: 1 (1^2+3^2 as 10 can be expressed in only 1 way in the powers of 2)
Input: 100,2
Output: 3 (10^2 ,6^2+8^2, 1^2+3^2+4^2+5^2+7^2 as 100 can be expressed in only 3 way)
Input: 10,3
Output: 1 (1^3+2^3,3^3+4^3 = 1+8+27+64 as 100 can be expressed in only 1 way in the powers of 3)
int count(int X, int N, int num) {
    int power = pow(num, N);
    if (power > X) {
        return 0;
    } else if (power == X) {
        return 1;
    } else {
        return count(X - power, N, num + 1) + count(X, N, num + 1);
    }
}

int powerSum(int X, int N) {
       return count(X,N,1);
}
