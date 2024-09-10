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
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(2*n);
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
            arr[i+n]=nums[i];
        }
        vector<int> ans(2*n,-1);
        stack<int> st;
        for(int i=0;i<2*n;i++){  //copying the array twice to make it circular
            while(!st.empty() && arr[i]>arr[st.top()]){
                    ans[st.top()]=arr[i];
                    st.pop();
            }
            st.push(i);
        }
        copy(ans.begin(), ans.begin()+n, nums.begin());
        return nums;
    }
};
class Solution { //brute force
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,-1);
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int a=(i+j)%n;
            if(nums[a]>nums[i]){
                arr[i]=nums[a];
                break;
            }
            }
        }
        
        return arr;
    }
};
