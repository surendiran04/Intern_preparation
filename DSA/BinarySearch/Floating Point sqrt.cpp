#include <bits/stdc++.h>
using namespace std;


double floatSqrtBinarySearch(double N, double epsilon) {
    if (N < 0) { // Handle negative input
        return -1.0;
    }
    if (N == 0) {
        return 0.0;
    }

    double low = 0.0;
    double high = N;

    // Adjust high for numbers between 0 and 1
    if (N < 1.0) {
        high = 1.0;
    }

    while ((high - low) > epsilon) {
        double mid = low + (high - low) / 2.0; // Prevent potential overflow with large (low+high)
        if (mid * mid < N) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low; // Or high, as they are very close
}

int main() {
    double number = 49.0;
    double precision = 0.0001; // Desired precision

    double result = floatSqrtBinarySearch(number, precision);

    std::cout << "The approximate square root of " << number << " with precision " << precision << " is: ";
    std::cout << std::fixed << std::setprecision(4) << result << std::endl; // Output formatted to 4 decimal places

    number = 0.25;
    result = floatSqrtBinarySearch(number, precision);
    std::cout << "The approximate square root of " << number << " with precision " << precision << " is: ";
    std::cout << std::fixed << std::setprecision(4) << result << std::endl;

    return 0;
}


