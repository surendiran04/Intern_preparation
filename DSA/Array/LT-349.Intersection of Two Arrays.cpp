Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
  
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
  
class Solution { //sorting approach
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        vector<int> s3;
        for(auto it=s1.begin();it!=s1.end();it++){
            for(auto i=s2.begin();i!=s2.end();i++){
                if(*(it)==*(i)){
                    s3.emplace_back(*it);
                }
            }
        }
        return s3;
    }
};
//more efficient code
class Solution {  //set doesn't contain duplicates 
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(),nums1.end());
        vector<int> result;
        for(int num :nums2){
                if(set1.count(num)){ //if count is 1 then set1 has the occurence of num
                    result.push_back(num);
                    set1.erase(num);
                }
        }
        return result;
    }
};
