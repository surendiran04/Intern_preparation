// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return 
// an array of the non-overlapping intervals that cover all the intervals in the input.
// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
  
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=prev[1]){
                prev[1]=max(prev[1],intervals[i][1]);
            }
            else{
                ans.push_back(prev);
                  prev=intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
