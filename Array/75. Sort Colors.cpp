// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Input: nums = [2,0,1]
// Output: [0,1,2]

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int track[] = {0,0,0};
        for (int num:nums)
        {
            track[num]++;
        }    
        int index = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<track[i];j++)
            {
                nums[index]=i;
                index++;
            }
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, n = nums.size();
        for(int num : nums) {
            if(num == 0) zeros++;
            else if(num == 1) ones++;
        }  
        for(int i = 0; i < zeros; ++i) {
            nums[i] = 0;
        }
        for(int i = zeros; i < zeros + ones; ++i) {
            nums[i] = 1;
        }
        for(int i = zeros + ones; i < n; ++i) {
            nums[i] = 2;
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        int i=0;
        for(const pair<int,int>x:map){
            for(int j=0;j<x.second;j++){
                nums[i++]=x.first;
            }
        }
    }
};
