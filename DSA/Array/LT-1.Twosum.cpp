class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
                  return {map[target-nums[i]],i};   //here we need to return the index of the elements which make the target 
            }
            map[nums[i]]=i; 
        return {-1,-1};
       
    }
};
