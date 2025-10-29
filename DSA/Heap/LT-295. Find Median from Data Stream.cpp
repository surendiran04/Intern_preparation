class MedianFinder {
public:
    vector<double> nums; //Got TLE since we don't know the size of the stream
    int n;
    MedianFinder() {
        n=0;
    }
    void addNum(int num) {
        nums.push_back(num);
        n++;
    }
    
    double findMedian() {
        int idx=n/2;
        sort(begin(nums),end(nums));
        if(n & 1){
            return nums[idx];
        }
        return (nums[idx-1]+nums[idx])/2;
    }
};
class MedianFinder {  //Perfect Approach
public:
    priority_queue<int> leftMax;
    priority_queue<int,vector<int>,greater<int>> rightMin;
    MedianFinder() {

    }
    void addNum(int num) {
        leftMax.push(num);
        if(!rightMin.empty() && rightMin.top()<leftMax.top()){
            rightMin.push(leftMax.top());
            leftMax.pop();
        }

        if(leftMax.size()>rightMin.size()+1){
            rightMin.push(leftMax.top());
            leftMax.pop();
        }else if(leftMax.size()<rightMin.size()){
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if(leftMax.size()==rightMin.size()){
            return (double)(leftMax.top()+rightMin.top())/2;
        }
        return (double)leftMax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
