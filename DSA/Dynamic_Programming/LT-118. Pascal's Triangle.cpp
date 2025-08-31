// Generating number of rows in pascal's triangle
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> d(i+1, 0);
            for (int j = 0; j < i+1; j++) {
                if (j == 0 || j == i) {
                    d[j] = 1;
                }else{
                    d[j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(d);
        }
        return ans;
    }
};
