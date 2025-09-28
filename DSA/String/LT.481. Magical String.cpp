// COunt the no of ones in the generated string
Input: n = 6
Output: 3  ,"122112"
class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) {
            return 1;
        }
        string s = "122";
        // vecto<char>
        int cnt_ones = 1;
        char to_insert = '1';
        int m = 3, i = 2;
        while (m < n) {
            int times = (s[i] == '2') ? 2 : 1;
            for (int k = 0; k < times && m < n; k++) {
                if (to_insert == '1')
                    cnt_ones++;
                s += to_insert;
                m++;
            }
            i++;
            to_insert = (to_insert == '1') ? '2' : '1';
        }
        return cnt_ones;
    }
};
