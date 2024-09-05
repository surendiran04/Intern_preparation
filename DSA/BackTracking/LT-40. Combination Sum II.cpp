// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [ [1,1,6], [1,2,5],[1,7],[2,6]]
// Input: candidates = [2,5,2,1,2], target = 5
// Output: [[1,2,2],[5]]
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<vector<int>> ans;
       vector<int> ds;
       f(0,target,candidates,ds,ans);
       return ans;
    }
    void f(int ind,int t,vector<int> &v,vector<int> &ds,vector<vector<int>> &ans){
        if(t<0){
            return;
        }
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<v.size();i++){
            if(i>ind && v[i]==v[i-1]){
                continue;
            }
            if(v[i]>t){
                break;
            }
            ds.push_back(v[i]);
            f(i+1,t-v[i],v,ds,ans);
            ds.pop_back();
        }
    }
};
