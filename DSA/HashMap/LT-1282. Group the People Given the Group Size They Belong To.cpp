// Input: groupSizes = [3,3,3,3,3,1,3]
// Output: [[5],[0,1,2],[3,4,6]]
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> map;
        vector<vector<int>> ans;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            map[groupSizes[i]].push_back(i);
        }
        for(auto x:map){
            int key=x.first;
            vector<int> value=x.second;
            for(int i=0;i<value.size();i+=key){  //moving i by key times
                vector<int> v;
                for(int j=i;j<i+key && j<value.size();j++){
                    v.push_back(value[j]);
                }
                ans.push_back(v);
            }
        }
        return ans;

    }
};
