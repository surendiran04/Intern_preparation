class Solution {
public:
    int numSteps(string s) { //manual simulation got failed since binary contains 500 digits
               int steps = 0;

        while (s != "1") {
            if (s.back() == '0') {
                // divide by 2
                s.pop_back();
            } else {
                // add 1
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            steps++;
        }
        return steps;

    }
};
