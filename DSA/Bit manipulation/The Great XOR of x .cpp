// We need to count the number of integers a that satisfy the conditions: 
//   1. Strictly Less Than x → 0<𝑎<𝑥
//   2.XOR Condition → a⊕x>x
// Understanding the XOR Condition
// The XOR operation a ^ x flips bits where a and x differ.
// a ^ x is greater than x if it sets a higher-order bit (compared to x).

// Sample Input
// 2   - 0010 k=1 2^k-1=1
// 10  - 1010 k=2 2^k-1=
// Sample output:
// 1 (1)
// 5 (1,4,5,6,7)
 for (long long a = 1; a < x; a++) { //Fails for bigger input due to time
        if ((a ^ x) > x) {
            count++;
        }
    }

#include <bits/stdc++.h>
using namespace std;
int countValidCreatures(long long x) {
    if (x == 0) return 0;
    int m = 63 - __builtin_clzll(x); // Find the position of the highest set bit , for x=1 -> 63 x=2 ->62 etc...
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        if ((x & (1LL << i)) == 0) {
            sum += (1LL << i);
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        cout << __builtin_clzll(x) << endl;
    }
    return 0;
}

__builtin_clz(x) - leading zeros before the last set bit (64 bit calculation) for x=1 -> 63,x=2 ->62
__builtin_ctz(x) - trailing zeros after the first set bit (64 bit calculation) for x=1 -> 0,x=2 ->1,x=4 -> 2
__builtin_popcount(x) - No of set bits (64 bit calculation) for x=1 -> 1, x=5 ->2
 __builtin_parity(x)	Returns 1 if number of 1 bits is odd, else 0
