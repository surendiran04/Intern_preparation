 long long subArrayRanges(vector<int>& nums) { //BruteForce
        int n=nums.size();
        if(n<2){
            return 0;
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX,maxi=INT_MIN;
            for(int j=i+1;j<n;j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                sum+=maxi-mini;
            }
           
        }
        return sum;
}

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) { //Optimised
        int n=nums.size();
        if(n<2){
            return 0;
        }
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=nextSmallerElement(arr);
        vector<int> pse=prevSmallerEqualElement(arr);
        long long ans=0;
        for(int i=0;i<n;i++){
           int right=nse[i]-i;
           int left=i-pse[i];
           ans=ans+1LL*left*right*arr[i];
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerEqualElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int> nge=nextGreaterElement(arr);
        vector<int> pge=prevGreaterEqualElement(arr);
        long long ans=0;
        for(int i=0;i<n;i++){
           int right=nge[i]-i;
           int left=i-pge[i];
           ans=ans+1LL*left*right*arr[i];
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nge(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> prevGreaterEqualElement(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pge(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
};
