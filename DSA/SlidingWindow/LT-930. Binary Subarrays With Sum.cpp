Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) { //hashmap approach
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;
        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};  
class Solution { //best approach sliding window
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    int atMost(vector<int>& nums, int goal){
        int i, j = 0, sum = 0, result = 0;
        for (i = 0; i< nums.size();i++) {
            sum += nums[i];
            while (sum > goal && j <= i) {
                sum -= nums[j];
                j++;
            }
            result += i - j + 1;
        }
        return result;
    }
};
