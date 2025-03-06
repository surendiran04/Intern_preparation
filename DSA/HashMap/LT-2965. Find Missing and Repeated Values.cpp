//Find the 2times occured number and not occured from a 2D matrix the matrix contains elements from [1,n^2]
// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
// Example 2:
// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> map;
        vector<int> res;
        for(vector<int> m:grid){
            for(int x:m){
                map[x]++;
                if(map[x]>1){
                    res.push_back(x);
                }
            }
        }
        for(int i=1;i<=n*n;i++){
            bool t1=map.find(i)==map.end();
            if(t1){
                res.push_back(i);
            }
        }
        return res;
    }
};
