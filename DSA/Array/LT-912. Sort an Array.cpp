class Solution {
public:
    vector<int> sortArray(vector<int>& nums) { //Counting Sort is very efficient when the range k is small relative to n
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int shift=-mini;
        vector<int> arr(maxi+shift+1,0);
        for(int num:nums){
            arr[num+shift]+=1;
        }
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            if(arr[i]){
                for(int j=0;j<arr[i];j++){
                    res.push_back(i-shift);
                }
            }
        }
        return res;
    }
};
