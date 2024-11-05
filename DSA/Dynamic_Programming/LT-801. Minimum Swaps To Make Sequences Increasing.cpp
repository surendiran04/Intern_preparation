// need to make both the arrays in increasing order with min no of swaps bw the elements in both the arrays.
// nums1=[0,4,4,5,9]
// nums2=[0,1,6,8,10]
// nums[1]=4 and nums2[1]=1 are interchnaged to make the array strictly in increasing order
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) { //similiar to increasing subsequence problem but didn't pass all cases
        int n=nums1.size();
        int swaps=0;
        for(int i=1;i<n;i++){
            if(nums1[i-1]>=nums1[i]){
                int t=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
                (nums2[t]>nums1[i-1])?swap(nums1[i],nums2[t]):(swap(nums1[i-1],nums2[t]));
                swaps++;
            }
        }
        for(int i=1;i<n;i++){
            if(nums2[i-1]>=nums2[i]){
                int t=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
                (nums1[t]>nums2[i-1])?swap(nums2[i],nums1[t]):(swap(nums2[i-1],nums1[t]));;
                swaps++;
            }
        }
        return swaps;
    }
};
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> keep(n,INT_MAX);
        vector<int> swap(n,INT_MAX);
        keep[0]=0;
        swap[0]=1;
        for(int i=1;i<n;i++){
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]) //already in strictly increasing order
            {
                keep[i]=keep[i-1];
                swap[i]=swap[i-1]+1;  //Try and do 1 swap
            }

            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) //by swapping 
            {
                keep[i]=min(keep[i],swap[i-1]);
                swap[i]=min(swap[i],keep[i-1]+1);
            }
        }
        return min(keep[n-1],swap[n-1]);
    }
};
