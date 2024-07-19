class Solution {  //best approach
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
private:
    vector<int> generateRow(int row) { //finding every row
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++) {
            ans =ans*(row-col);
            ans = ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};

class Solution { //brute force to find every element
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++) {
            int n = i + 1;
            for (int c = 1; c <= n; c++) {
                result[i].push_back(NCR(n-1,c-1));
            }
        }
        return result;
    }

private:
    int NCR(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }
};


#include<bits/stdc++.h>
using namespace std;
int NCR(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int main(){ 
   int n=5;  //if they ask nth row
   for(int c=1;c<=n;c++){
       cout<<NCR(n-1,c-1)<<endl;
   }
}
