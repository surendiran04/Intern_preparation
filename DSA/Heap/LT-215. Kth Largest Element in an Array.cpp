// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i:nums){
            maxHeap.push(i);
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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Push elements into the min-heap and maintain size k
        for (int i : nums) {
            minHeap.push(i);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top of the heap is now the Kth largest element
        return minHeap.top();
    }
};
