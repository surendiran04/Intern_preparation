// Input:
// n = 5
// bt = [4,3,7,1,2]
// Output: 4
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        sort(bt.begin(),bt.end());
        int wt=0;
        int t=0;
        for(int i=0;i<n;i++){
            wt+=t;
            t+=bt[i];
        }
        return (wt/n);
    }
};
