#include<bits/stdc++.h>
using namespace std;
int getMask(string s) {
    int mask = 0;
    for (char c : s) {
        if (c == 'x') mask |= 1;
        if (c == 'y') mask |= 2;
        if (c == 'z') mask |= 4;
    }
    return mask;
}

int minCostToBuyXYZ(vector<int>& price, vector<string>& items) {
   const int INF = 1e9;
    vector<int> dp(8, INF);
    dp[0] = 0;

    int n = price.size();
    for (int i = 0; i < n; i++) {
        int cm = getMask(items[i]);
        for (int old = 0; old < 8; old++) {
            int nm = old | cm;
            dp[nm] = min(dp[nm], dp[old] + price[i]);
        }
    }

    if (dp[7] == INF) return -1;  // Impossible to cover x,y,z
    return dp[7];
}
long long countNegativeProductSubseq(vector<int>& a) {
    int neg = 0, pos = 0, zero = 0;
    for (int x : a) {
        if (x == 0) zero++;
        else if (x < 0) neg++;
        else pos++;
    }

    if (neg == 0) return 0; // cannot get negative product

    long long subsets_pos = (1LL << pos);
    long long subsets_neg_odd = (1LL << (neg - 1));

    return subsets_pos * subsets_neg_odd;
}


int main(){
    vector<int> price={5,6,16,4};
    vector<string> items={"z","y","yxz","x"};
    cout<<minCostToBuyXYZ(price,items)<<endl; //15
    vector<int> price1={10,15};
    vector<string> items1={"xy","yz"};
    cout<<minCostToBuyXYZ(price1,items1)<<endl; //25 but in oa ans is -1
  
    vector<int> arr={1,2,-1,-2},arr2={1,2,-1,-2,-3}; //Find the no of susbsequence that make the product negative
    cout<<countNegativeProductSubseq(arr)<<" "<<countNegativeProductSubseq(arr2)<<endl; //8 , 16 (single element also counts)
}
