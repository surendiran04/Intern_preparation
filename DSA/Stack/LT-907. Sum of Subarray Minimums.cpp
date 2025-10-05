class Solution { //Got TLE
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0,mini;
        for(int i=0;i<n;i++){
            mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                ans+=mini;
            }
            ans=ans%mod;
        }
        return ans;
    }
};
// arr=[1,4,6,7,3,7,8,1]
// let's consider index 4 which is element 3 so how many subarray will have min element as 3 actually 12 subaaray [4,6,7,3,7,8] so sum will 12*element = 36
// How 12? next smaller element of 3 is 1 which is at index 7,so 7-4=3 ,previous smaller or equal element of 3 is at index 0 which 1 4-0=4
//why previous smaller or eql element consider case [1,1] here 1st 1 goes 2 times and 2nd 1 computes 1 time but if we use pse we' get 2 for 2nd one
// so use psee - previous smaller or eql element store index in stack and psee array

class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=nextSmallerElement(arr);
        vector<int> pse=prevSmallerEqualElement(arr);
        int ans=0;
        for(int i=0;i<n;i++){
           int right=nse[i]-i;
           int left=i-pse[i];
           ans=(ans+(1LL*left*right*arr[i])%mod)%mod;
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
};
