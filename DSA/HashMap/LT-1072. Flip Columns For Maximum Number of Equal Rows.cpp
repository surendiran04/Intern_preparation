// Want to make the whole row the same by flipping the col of every cell
// Return the maximum number of rows that have all values equal after some number of flips.
// Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2  If we flip the first 2 cols then matrix = [[1,1,0],[1,1,1],[0,0,0]] -last 2 rows are fully equal
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
         unordered_map<string, int> patternFrequency;
        for (auto& currentRow : matrix) {
            string patternBuilder = "";
            for (int col = 0; col < currentRow.size(); col++) {
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }
            patternFrequency[patternBuilder]++;
        }
        int maxFrequency = 0;
        for (auto& entry : patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};
