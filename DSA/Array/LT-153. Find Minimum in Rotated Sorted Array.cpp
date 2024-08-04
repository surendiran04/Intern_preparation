class Solution { //the array is sorted and we have to find the min element
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int m=(l+h)/2;
            if(nums[m]>nums[h]){ //if the array is sorted we can use binary search 
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return nums[h];
    }
};
