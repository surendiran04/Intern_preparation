// The output should be an integer representing the maximum possible sum of the selected rectangular subgrid.
// Sample Input 0
// 4 4
// 62 -4 71 17
// -71 -76 23 -5
// -38 -27 -61 -86
// 47 -8 -46 -23
// Sample Output 0
// 146
// The maximum sum comes from the first row of the matrix(red rectangle): [62, -4, 71, 17]. The sum of these numbers is 146, which is the highest sum possible from any rectangular submatrix in the matrix.

// Sample Input 1
// 2 10
// -65 83 24 -63 82 -9 -7 -34 -1 20
// 16 -93 36 -35 -66 81 22 36 92 44
// Sample Output 1
// 275  [81,22,36,92,44]

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
int maxSum(vector<vector<int>>& mat,int n,int m){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        vector<int> t(m,0);
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++){
                t[k]+=mat[j][k];
            }
            int sum=0,sum1=INT_MIN;
            for(int num:t){
                sum=max(num,sum+num);
                sum1=max(sum1,sum);
            }
            maxSum=max(sum1,maxSum);
            
        }
    }
    return maxSum;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<maxSum(mat,n,m)<<endl;
    return 0;
}
