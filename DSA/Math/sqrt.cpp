#include <iostream>
using namespace std;

int floorSqrt(int x) {
    if (x == 0 || x == 1) return x;

    int start = 1, end = x / 2, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        int sqr = mid * mid;

        if (sqr == x) return mid;
        if (sqr <= x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int number = 17;
    cout << "The floor square root of " << number << " is " << floorSqrt(number) << endl;
    return 0;
}
