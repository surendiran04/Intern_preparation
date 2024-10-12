// Return the minimum number of groups you need to make.Two intervals intersect if there is at least one common number between them.
// For example, the intervals [1, 5] and [5, 8] intersect.
// Example 1:
// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
    
// Example 2:
// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
// Output: 1
    
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
