class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int num:nums){
            minheap.push(num);
        }
    }
    int add(int val) {
        minheap.push(val);
        while(minheap.size()>K){
            minheap.pop();
        }
        return minheap.top();
    }
};

class KthLargest { //Got TLE
public:
    vector<int> arr;
    int n;
    KthLargest(int k, vector<int>& nums) {
        arr.clear();
        n=k;
        arr.insert(arr.end(),nums.begin(),nums.end());
    }
    int add(int val) {
        arr.push_back(val);
        sort(begin(arr),end(arr));
        return arr[arr.size()-n];
    }
};
