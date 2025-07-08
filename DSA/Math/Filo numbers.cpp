//No of ways such that the consecutive numbers sum is equal to the number
// input: 15
// op:4 (1+2+3+4+5),(8+7),(4+5+6),(15)
// input:9
// op:3 (4+5),(9),(2+3+4)

#include <iostream>
using namespace std;

int countFiloWays(int N) {
    int count = 0;
    // Try all possible values of k such that k(k+1)/2 <= N
    for (int k = 1; k * (k + 1) / 2 <= N; ++k) {
        // Check if (N - k*(k-1)/2) is divisible by k
        int numerator = N - k * (k - 1) / 2;
        if (numerator % k == 0) {
            // x = numerator / k is a valid starting number
            int x = numerator / k;
            if (x > 0) count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    // Call user logic function and print the output
    int result = countFiloWays(n);
    cout << result << endl;

    return 0;
}
