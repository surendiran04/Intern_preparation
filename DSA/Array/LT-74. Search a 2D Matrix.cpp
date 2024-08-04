class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, h = row * col - 1; //binary search approach
        while (l <= h){
            int mid = l + (h - l) / 2;
            int tC = mid % col;
            int tR = mid / col;
            if (matrix[tR][tC] == target)
                return true;
            if (matrix[tR][tC] < target)
                l = mid + 1;
            else
                 h = mid - 1;
        }
        return false;
     } 
};
