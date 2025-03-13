// Return the minimum possible k - no of queries need to processed to make a zero array
// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
// Output: 2
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        for (int index = 0; index < n; index++) {
               // Iterate through queries while current index of nums cannot equal zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};

