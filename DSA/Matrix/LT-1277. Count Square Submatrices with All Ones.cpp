// Need to how many sqaure matrix can be formed from the given matrix 
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        int size=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;  
                    }
                    size += dp[i][j];
                }
            }
        }
         // [0,1,1,1],
         // [1,1,2,2],  Ending place will have the possibility of forming a matrix of size
         // [0,1,2,3]
        return size;
    }
};

class Solution {  //Inplace dp technic
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += min(matrix[i - 1][j], 
                                        min(matrix[i][j - 1], matrix[i - 1][j - 1])); //since already the pos has 1 simply add it with the current
                }
            }
        }

        int total = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                total += matrix[i][j];
            }
        }

        return total;
    }
};
