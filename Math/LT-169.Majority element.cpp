// The majority element is the element that appears more than ⌊n / 2⌋ times.
// Input: nums = [3,2,3]
// Output: 3
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
  
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size()/2;
        for(auto a:nums){
            map[a]++;
        }
        for (auto a : map) {
            if (a.second > n) {
                return a.first; 
            }
        }
        return 0;
    }
};

class Solution { //best approach with linear time and O(1)space
public:
    int majorityElement(vector<int>& v) {
        int cnt = 0;
        int el;
        int n = v.size();
         for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = v[i];
            } else if (v[i] == el) {
                cnt++;
            } else {
                cnt --;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el)
                cnt1++;
        }
        if (cnt1 > (n/ 2)) {
            return el;
        }
        return -1;
    }
};
