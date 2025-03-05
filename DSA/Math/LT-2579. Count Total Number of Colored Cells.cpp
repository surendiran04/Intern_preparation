// n=1, 1
// n=2, 1+4
// n=3, 1+4+8
// n=4, 1+4+8+12
// and so on!

class Solution {
public:
    long long coloredCells(int n) {
        return pow(n,2)+pow(n-1,2);
    }
};
