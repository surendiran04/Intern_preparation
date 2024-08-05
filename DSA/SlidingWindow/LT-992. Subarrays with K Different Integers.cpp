// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:
// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums, k) - countSubarraysWithAtMostKDistinct(nums, k - 1);
    }
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        int start = 0;
        int count = 0;
        unordered_map<int, int> frequencyMap;
        for (int end = 0; end < nums.size(); end++) {
            frequencyMap[nums[end]]++;
            while (frequencyMap.size() > k) {
                frequencyMap[nums[start]]--;
                if (frequencyMap[nums[start]] == 0) {
                    frequencyMap.erase(nums[start]);
                }
                start++;
            }
            count += end - start + 1;
        }
        return count;
    }
};


