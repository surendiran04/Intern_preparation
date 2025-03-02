// Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
// Output: [[1,6],[2,3],[3,2],[4,6]]
// Explanation: The resulting array contains the following:
// - id = 1, the value of this id is 2 + 4 = 6.
// - id = 2, the value of this id is 3.
// - id = 3, the value of this id is 2.
// - id = 4, the value of this id is 5 + 1 = 6.
// Example 2:
// Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
// Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
// Explanation: There are no common ids, so we just include each id with its value in the resulting list.

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) { //can also use ordered_map
        vector<vector<int>> res;
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i][0]==nums2[j][0]){
                res.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;j++;
            }else if(nums1[i][0]<nums2[j][0]){
                res.push_back(nums1[i]); 
                i++;
            }else{
                res.push_back(nums2[j]); 
                j++;
            }
        }
        while(i<n1){
                res.push_back(nums1[i]); 
                  i++;
        }
        while(j<n2){
                 res.push_back(nums2[j]); 
                j++;
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
//                                     vector<vector<int>>& nums2) {
//         map<int, int> keyToSum;

//         // Copying the array nums1 to the map.
//         for (auto nums : nums1) {
//             keyToSum[nums[0]] = nums[1];
//         }

//         // Adding the values to existing keys or create new entries.
//         for (auto nums : nums2) {
//             keyToSum[nums[0]] += nums[1];
//         }

//         vector<vector<int>> mergedArray;
//         for (auto it : keyToSum) {
//             mergedArray.push_back({it.first, it.second});
//         }

//         return mergedArray;
//     }
// };
