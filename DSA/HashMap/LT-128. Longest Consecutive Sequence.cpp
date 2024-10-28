// Return the maximum consecutive integers if there is no one and size()>0 then return 1
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1){
            return 0;
        }
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        int len=0,maxlen=1;
        for(auto x:map){
            int first=x.first;
            if(map.find(first-1)==map.end() && map.find(first+1)!=map.end()){
                len++;
                while(map.find(first+len)!=map.end()){
                    len++;
                }
                maxlen=max(maxlen,len);
                len=0;
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) { //slightly modified
        if(nums.size()<1){
            return 0;
        }
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        int maxlen=0;
        for(auto x:map){
            int first=x.first;
            if(map.find(first-1)==map.end()){
                int len=1;
                while(map.find(first+len)!=map.end()){
                    len++;
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};
