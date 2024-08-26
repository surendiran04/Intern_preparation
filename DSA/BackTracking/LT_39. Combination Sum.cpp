class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, 0, candidates, ans, ds);
        return ans;
    }
    void findCombination(int ind, int target, int sum, vector<int> arr,
                         vector<vector<int>>& ans, vector<int>& ds) {    //picking every combination without permutated ans
        if (target == sum){
            ans.push_back(ds);
            return;
        }
        if (sum > target || ind >= arr.size()) {
            return;
        }
        ds.push_back(arr[ind]);
        findCombination(ind, target, sum + arr[ind], arr, ans, ds);
        ds.pop_back();
        findCombination(ind + 1, target, sum, arr, ans, ds);
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { //this code produces all possible combination with permutation that is not needed for this ans
       vector<vector<int>> ans;
       vector<int> ds;
       findCombination(0,target,candidates,ans,ds);
       return ans;
    }
    void findCombination(int ind,int target,vector<int> arr,vector<vector<int>>& ans,vector<int>& ds){
        if(ind==arr.size()){
            if(target==0)
               ans.push_back(ds);
            return ;   
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(0,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findCombination(ind+1,target,arr,ans,ds);
    }
};
