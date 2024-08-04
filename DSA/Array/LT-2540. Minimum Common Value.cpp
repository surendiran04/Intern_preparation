Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. 
If there is no common integer amongst nums1 and nums2, return -1.

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
  
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
     int i=0,j=0,s1=nums1.size(),s2=nums2.size();
     while(i<s1 && j<s2)
     {
         if(nums1[i]<nums2[j])
         i++;
         else if(nums1[i]==nums2[j])
         return nums2[j];
         else
         j++;
     } 
     return -1;
    }
};
