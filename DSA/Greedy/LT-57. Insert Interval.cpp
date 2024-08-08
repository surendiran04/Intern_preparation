// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n=intervals.size();
        vector<vector<int>> ans;
        while(i<n && intervals[i][1]<newInterval[0]){ //pushing the non-overlappping intervals [2,5] - new[3,7] it'll overlap with [2,5]
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<= newInterval[1]){  // new [5,8] - [8,10] = [5,10]
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval); 
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
