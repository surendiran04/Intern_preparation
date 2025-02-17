// binary string is a string which contains only “0” and “1” s). In this series F(1) = “0” , F(2) = “1” F(3) = “01” ………..  F(n) = F(n-2) + F(n-1).
// The first line of input will be one integer Q denoting the number of queries.
// The next Q line of input will contain a positive integer n.
// Output Format
// For each query print  the absolute difference of the number of “0's" and “1's" in F(n).
// As the number can be very large print the answer modulo 1e9+7.
// Constraints
// 1<= Q <= 10^6 , 1<= n <= 10^7
// Sample Testcase 0
// Testcase Input
// 3
// 4
// 5
// 6
// Testcase Output
// 1
// 1
// 2
// Explanation
// F(4) = “101” so the absolute difference between the number of “1’s” and the number of “0’s” is 1.
// F(5)= “01101” and F(6) = “10101101” so the  absolute difference between the number of “1’s” and the number of “0’s” are 1 and 2 respectively.
// Sample Testcase 1
// Testcase Input
// 2
// 7
// 3
// Testcase Output
// 3
// 0
// Explanation
// F(7) = “0110110101101” , here the number of “1’s” is 8 and number of “0’s” is 5 so the absolute difference is 3.
// F(3) = “01” so the absolute difference is 0.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_FIB = 10000000; // Since n can be up to 1e7, k = n-3 <= 1e7-3

int Fib[MAX_FIB + 1];

void precompute_fib() {
    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= MAX_FIB; ++i) {
        Fib[i] = (Fib[i-1] + Fib[i-2]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_fib();

    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "1\n";
        } else if (n == 3) {
            cout << "0\n";
        } else {
            int k = n - 3;
            cout << Fib[k] << "\n";
        }
    }

    return 0;
}
