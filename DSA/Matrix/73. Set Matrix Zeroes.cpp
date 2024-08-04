// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
         int m=matrix.size();
         int n=matrix[0].size();
         vector<int> row(m,0);
         vector<int> col(n,0);
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
         }
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
         }
    }
};


    int col0 = 1;  //instead of using two arrays as extra space - marking [0]th index of that row or col as identity to make row & col as zero respectively
    for (int i = 0; i < n; i++) {            //best approach - uses constant space
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    // Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

//brute force
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
