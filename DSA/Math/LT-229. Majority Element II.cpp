// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Example 1:
// Input: nums = [3,2,3]
// Output: [3]
// Example 2:
// Input: nums = [1]
// Output: [1]
// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

// points to know if there are n elements in an array at max only 2 elements can occur n/3+ times
  
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<2){
            return nums;
        }
        int n=nums.size()/3;
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        vector<int> res;
        for(auto x:map){
            if(x.second>n){
                res.push_back(x.first);
            }
        }
        return res;
    }
};

class Solution { //slightly optimised
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<2){
            return nums;
        }
        int n=nums.size()/3+1;
        vector<int> res;
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
            if(map[num]==n){
                  res.push_back(num);
            }
          if(res.size()==2){
                break;
            }
        }
        return res;
    }
};

class Solution {  //similiar apparoach to majority element  
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int num:nums){
            if(cnt1==0 && num !=ele2){
                cnt1=1;
                ele1=num;
            }
            else if(cnt2==0 && num !=ele1){
                cnt2=1;
                ele2=num;
            }
            else if(num==ele1){
                cnt1++;
            }
            else if(num==ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int num:nums){ //found the possible elements which can have the count more than n/3
            if(ele1==num) cnt1++;
            else if(ele2==num) cnt2++;
        }
        vector<int> res;
        if(cnt1>n/3) res.push_back(ele1);
        if(cnt2>n/3) res.push_back(ele2);
        return res;
    }
};
