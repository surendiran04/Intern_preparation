// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, 
// sort them in decreasing order.Return the sorted array.
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:
// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:
// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        int n=nums.size();
        vector<vector<int>> v(n+1);
        for(const pair<int,int>x:map){
            v[x.second].push_back(x.first);
        }
        vector<int> res;
        for(int i=1;i<=n;i++){
            if(!v[i].empty()){
                if(v[i].size()>1){
                  sort(v[i].begin(),v[i].end(),greater<int>());
                }
                for(int j=0;j<v[i].size();j++){
                    for(int k=0;k<i;k++){
                        res.push_back(v[i][j]);
                    }
                    
                }
            }
        }
        return res;
    }
};
