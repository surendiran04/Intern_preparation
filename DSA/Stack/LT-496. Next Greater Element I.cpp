//given two arrays nums1 and nums2 if the element is nums1 is found in nums2 then find the element's next greater element in nums2 else return -1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { //Montonic stack approach
        
        int n=nums2.size();
        unordered_map<int,int> map;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            map[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int num:nums1){
            res.push_back(map[num]);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans(nums1.size(), -1); 
        for (int i = 0; i < nums1.size(); i++){
            int j = 0;
            while(nums2[j] != nums1[i]){
                j++;
            }
            // search for the next greater element 
            for(int k = j + 1; k < nums2.size(); k++){
                if(nums2[k] > nums1[i]) {
                    ans[i] = nums2[k];
                    break;
                }
            }
        }
        return ans;
        
    }
};
class Solution { //high time complexity
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> map;
        vector<int> res;
        for(int num:nums2){
            while(!s.empty() && s.top()<num){
                map[s.top()]=num;
            }
            s.push(num);
        }
        for(int num:nums1){
            if(map.find(num)!=map.end()){
                res.push_back(map[num]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
        
    }
};

#include <iostream> //if two arrays are sorted
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            auto j=find(nums2.begin(),nums2.end(),nums1[i]);
            if(j!=nums2.end()){
                res[i]=nextGreater(nums2,j-nums2.begin());
            }
        }
        return res;
        
    }
    int nextGreater(vector<int>nums,int j){
        while(j<nums.size()-1){
            if(nums[j]<nums[j+1]){
                return nums[j+1];
            }
            j++;
        }
        return -1;
    }
};
 
int main() {
 
    int A[] = {1,2,3, 5, 7};
    vector<int> v;
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        v.emplace_back(A[i]);
    }
    vector<int> v2={1,2,8,9,10};
    Solution s;
    vector<int>v1=s.nextGreaterElement(v,v2);
    for(int j:v1){
        cout<<j<<endl;
    }
 
    return 0;
}
