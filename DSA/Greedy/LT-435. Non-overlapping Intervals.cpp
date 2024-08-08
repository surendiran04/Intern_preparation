// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
//arranging the vectors based on the end values so [1,2],[2,3],[1,3],[3,4]   
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<2){
           return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int cnt=1,last_ind=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=last_ind){ //checking which ever the vectors are not overlapping
                cnt++;
                last_ind=intervals[i][1];
            }
        }
        return n-cnt; //finding the overlapping count
    }
};
