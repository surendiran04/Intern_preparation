//i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
// Example 2:

// Input: nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
//nums=[2,2,1] output:1
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){ //decreasing order of indices
            if(st.empty() || nums[st.top()] > nums[i]){
               st.push(i);
            } 
        }
        int ramp=0;
        for(int j=n-1;j>=0;j--){ //traversing from last to get max ramp
            while(!st.empty() && nums[st.top()]<=nums[j]){
                ramp=max(ramp,j-st.top());
                st.pop();
            }
        }
        return ramp;
    }
};
