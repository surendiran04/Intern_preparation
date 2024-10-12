class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(auto in:intervals){
            if(!minheap.empty() && minheap.top()<in[0]){
                minheap.pop();
            }
            minheap.push(in[1]);
        }
        return minheap.size();
    }
};
