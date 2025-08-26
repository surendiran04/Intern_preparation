// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.
 
// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

class Solution {
public:
    static bool comparator(string& a,string& b){
            return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> res(n);
        for(int i=0;i<n;i++){
            res[i]=to_string(nums[i]);
        }
        sort(res.begin(),res.end(),comparator);
        if (res[0] == "0") return "0";
        string ans="";
        for(auto st:res){
            ans+=st;
        }
        return ans;
    }
};
