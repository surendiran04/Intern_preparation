//We can multiply 2 adjacent elements by -1 if they are negative and make it positive and give the maximum possible sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;
        for (auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                    minAbsVal = min(minAbsVal, abs(val));
                }
            }
        }
        if (negativeCount % 2 != 0) { //If there are odd no of negative values then we can't make one element as minus
            totalSum -= 2 * minAbsVal;  // so we minus it from the totalSum and the existing sum for it's minus sign
        }

        return totalSum;
    }
};
