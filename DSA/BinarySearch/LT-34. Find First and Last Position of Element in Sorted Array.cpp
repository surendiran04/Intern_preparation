// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {  //brute force
        int n=nums.size();
        int l=0,r=n-1,mid;
        pair<int,int> ans={-1,-1};
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=helper(nums,target,mid);\
                break;
            }else if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return {ans.first,ans.second};
    }
    pair<int,int> helper(vector<int>& nums,int t,int mid){
        int l=mid,r=mid;
        while(l-1>-1 && nums[l-1]==t){
            l--;
        }
        while(r+1<nums.size() && nums[r+1]==t){
            r++;
        }
        return {l,r};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { //in-built
        vector<int> v={-1,-1};
        if(nums.empty()){
            return v;
        }
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin(); 
        int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(i!=nums.size() && nums[i]==target && nums[j-1]==target && j>=0){
            v.clear();
            v.push_back(i);
            v.push_back(j-1);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { //calling bin fn twice
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return idx;
    }    
};
