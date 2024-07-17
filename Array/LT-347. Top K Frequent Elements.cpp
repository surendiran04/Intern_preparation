// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
  
class Solution {   //return the k number of elements which has the max frequency
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int num:nums){   //found the count every elements
            map[num]++;
        }
        int n=nums.size();
        vector<vector<int>> v(n+1);
        for(const pair<int, int>& x : map){   //Making the count as index and adding elements in it
            v[x.second].push_back(x.first);
        }
        for(int i=n;i>0 && k;i--){    
            if(!v[i].empty()){
                for(const int& m : v[i]){  //once we found the top k elements loop breaks
                     res.push_back(m);
                     k--;
                }   
            }
        }
        return res;
    }
};
