class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
            }
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

class Solution { //binary search
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }   
private:
    int countLessEqual(const vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1; // All elements in this column up to this row are <= mid
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
};
