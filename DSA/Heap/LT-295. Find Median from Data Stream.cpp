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

// Follow up:
// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
class MedianFinder {
public:
    vector<int> count;
    int n;

    MedianFinder() : count(101, 0), n(0) {}

    void addNum(int num) {
        count[num]++;
        n++;
    }

    double findMedian() {
        int mid1 = (n + 1) / 2;
        int mid2 = (n + 2) / 2;  // handles even-length case
        int cumsum = 0;
        int m1 = -1, m2 = -1;

        for (int i = 0; i <= 100; i++) {
            cumsum += count[i];
            if (m1 == -1 && cumsum >= mid1) m1 = i;
            if (m2 == -1 && cumsum >= mid2) m2 = i;
        }
        return (m1 + m2) / 2.0;
    }
};
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

Use two structures:
*count[101] for the main range
*Two count pointers (<0 and >100)
