Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
    
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.    
    
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { //using map to count the frequency
        vector<int> result;
        unordered_map<int,int> map;
        for(int num:nums1){
            map[num]++;
        }
        for(int num:nums2){
            if(map.find(num)!=map.end() && map[num]>0){
                result.push_back(num);
                map[num]--;
            }
        }
        return result;
    }
};
class Solution { //sorting technique - uses less space
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
    }
};
