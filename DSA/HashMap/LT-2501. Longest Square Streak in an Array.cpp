//find the length of the longest subsequence if length of the subsequence is at least 2 else -1
//Input: nums = [4,3,6,16,8,2]
//Output: 3
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }
        unordered_map<long long, int> map;
        for (int num : nums) {
            map[num]++;
        }
        int longest = -1;
        for (auto x : map) {
            long long n = x.first;
            int len=0;
            while (map.find(n) != map.end()) {
                n = n * n;
                if(n>1e5) break;
                len++;
            }
            longest = max(longest, len);
        }
        return longest>1?longest:-1;
    }
};
