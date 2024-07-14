// Given an integer, we need to find the super digit of the integer.
// If x has only 1 digit, then its super digit is x.
// Otherwise, the super digit of x is equal to the super digit of the sum of the digits of x.
// SampleInput:
// If n='9875' and k=1
// 	super_digit(9875)   	9+8+7+5 = 29 
// 	super_digit(29) 	2 + 9 = 11
// 	super_digit(11)		1 + 1 = 2
// 	super_digit(2)		= 2  
// If n='9875' and k=4
//  superDigit(p) = superDigit(9875987598759875)
//                   9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
//     superDigit(p) = superDigit(116)
//                   1+1+6 = 8
//     superDigit(p) = superDigit(8)
#include <iostream>
#include <cstring>
#include <numeric>
int sumOfDigits(const char* str) {
    int sum = 0;
    while (*str) {
        sum += *str - '0';
        ++str;
    }
    return sum;
}
int superDigit(const char* str) {
    if (strlen(str) == 1) {
        return str[0] - '0';
    }
    int sum = sumOfDigits(str);
    char sumStr[12]; // To hold the sum as a string (max 10 digits + null terminator)
    sprintf(sumStr, "%d", sum);
    return superDigit(sumStr);
}

int main() {
    const char* n = "9875";
    int k = 4;
    int len = strlen(n);
    int totalLen = len * k;
    char* concatenatedStr = new char[totalLen + 1]; 
    concatenatedStr[0] = '\0'; 
    for (int i = 0; i < k; ++i) {
        strcat(concatenatedStr, n);
    }
    int result = superDigit(concatenatedStr);
    std::cout << "Super Digit: " << result << std::endl;
    delete[] concatenatedStr;
    return 0;
}
