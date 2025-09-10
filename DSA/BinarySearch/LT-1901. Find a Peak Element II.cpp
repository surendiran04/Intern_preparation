// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) { //potentially finding the max val in the matrix by bin search
        int n=mat.size(),m=mat[0].size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=l+(r-l)/2;  //mid is the col
            int maxrowIdx=findMaxIdx(mat,n,m,mid);
            int left=mid-1>=0?mat[maxrowIdx][mid-1]:-1;
            int right=mid+1<m?mat[maxrowIdx][mid+1]:-1;
            if(left<mat[maxrowIdx][mid] && mat[maxrowIdx][mid]>right){
                return {maxrowIdx,mid};
            }else if(mat[maxrowIdx][mid]<left){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
    int findMaxIdx(vector<vector<int>>& mat,int n,int m,int col){
        int maxval=-1,maxIdx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxval){ //finding the row which has max value in selected col
                maxval=mat[i][col];
                maxIdx=i;
            }
        }
        return maxIdx;
    }
};
