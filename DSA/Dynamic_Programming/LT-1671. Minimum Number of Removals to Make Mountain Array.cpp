//A mountain array is defined as one that first strictly increases to a peak element at an index say i, then strictly decreases after that. 
//Return  the moves to make the array a mountain array
// Input: nums = [1,3,1]
// Output: 0
// Input: nums = [2,1,1,5,6,2,3,1]
// Output: 3
// Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
class Solution {
public:
    vector<int> getLongestIncreasingSubsequenceLength(const vector<int>& v) {
        vector<int> lisLen(v.size(), 1);
        vector<int> lis = {v[0]};

        for (int i = 1; i < v.size(); i++) {
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            if (index == lis.size()) {
                lis.push_back(v[i]);
            } else {
                lis[index] = v[i];
            }
            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);
        
        vector<int> ldsLength(N, 1);
        vector<int> lds = {nums[N - 1]};

        for (int i = N - 2; i >= 0; i--) {
            int index = lower_bound(lds.begin(), lds.end(), nums[i]) - lds.begin();
            if (index == lds.size()) {
                lds.push_back(nums[i]);
            } else {
                lds[index] = nums[i];
            }
            ldsLength[i] = lds.size();
        }

        int minRemovals = INT_MAX;
        for (int i = 1; i < N - 1; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals = min(minRemovals, N - (lisLength[i] + ldsLength[i] - 1));
            }
        }

        return minRemovals;
    }
};
