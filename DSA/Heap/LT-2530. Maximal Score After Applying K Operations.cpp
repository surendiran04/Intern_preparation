class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i:nums){
            maxHeap.push(i);
        }
        long long s=0;
        for(int i=0;i<k;i++){ //always add the top k frequent elements
            int val=maxHeap.top();
            maxHeap.pop();
            s+=val;
            maxHeap.push((val+2)/3);  //ceil = a/b = (a+b-1)/b in this case b=3 so b-1 = 2
        }
        return s;
    }
};
