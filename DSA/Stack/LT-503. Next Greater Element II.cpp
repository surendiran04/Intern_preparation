// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() &&  nums[st.top()]<nums[i] ){ 
                v[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; ++i) { //circular check
            while (!st.empty() && nums[st.top()] < nums[i]) { //if a element's index in stack means it can also have the element prev
                v[st.top()] = nums[i];
                st.pop();
            }
        }
        return v;
    }
};
