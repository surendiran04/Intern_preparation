class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {   // T(n) - O(M*M/2)
        int M=matrix.size();
        for (int i = 0; i <M; i++) {  //transpose of matrix
            for (int j = i + 1; j < M; j++){    
                if(i!=j){
                     swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<M;i++){    // T(n) - O(M^2)
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
