// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its
// next greater number.If it doesn't exist, return -1 for this number.
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=0;i<2*n;i++){
            int num=nums[i%n];
            while(!st.empty() && nums[st.top()]<num){
                res[st.top()]=num;
                st.pop();
            }
            if(i<n){
                st.push(i);
            }   
        }
        return res;
    }
};
