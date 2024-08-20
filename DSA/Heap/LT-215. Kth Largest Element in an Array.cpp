class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i:nums){
            maxHeap.push(nums[i]);
        }
        if(k==1){
            return maxHeap.top();
        }
        while(k>1){
            maxHeap.pop();
            k--;
        }
        return maxHeap.top();
    }
};
