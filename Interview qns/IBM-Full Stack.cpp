//For every element in array1 find the greater element's index (1-based index) in array2.If any duplicates in array2 return the left most index.
//For every arr1[i]<arr2[j] find the smallest j+1 (1-based indexing) if not -1.

arr1=[2,8,7,4,6] arr2=[3,5,7,3] ans:1,-1,-1,2,3
   
arr1 = [4] //critical edge case
arr2 = [6,5,7]
ans:1 (since 6 is the 1st greater element)

// Initiall approach was to store the arr2 as a pair(val,index+1) and sort it and do a upper bound and find the number although it worked for most of the tc failed some.


#include <bits/stdc++.h>
using namespace std;

vector<int> getFirstCompatible(vector<int>& arr1, vector<int>& arr2) { //This approach overcomed the edge case
    int n = arr1.size(), m = arr2.size();

    // Store arr2 with original indices (1-based)
    vector<pair<int, int>> arr2_pairs;
    arr2_pairs.reserve(m);
    for (int i = 0; i < m; ++i)
        arr2_pairs.emplace_back(arr2[i], i + 1);


    sort(arr2_pairs.begin(), arr2_pairs.end(), [](auto &a, auto &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second; 
    });

    // Precompute suffix-minimum of indices
    // sufMinIdx[i] = smallest original index among elements >= arr2_pairs[i]
    vector<int> sufMinIdx(m);
    sufMinIdx[m - 1] = arr2_pairs[m - 1].second;
    for (int i = m - 2; i >= 0; --i)
        sufMinIdx[i] = min(arr2_pairs[i].second, sufMinIdx[i + 1]);

    // Extract sorted values for binary search
    vector<int> arr2_vals;
    arr2_vals.reserve(m);
    for (auto &p : arr2_pairs)
        arr2_vals.push_back(p.first);

    // Result array
    vector<int> res;
    res.reserve(n);

    for (int x : arr1) {
        auto it = upper_bound(arr2_vals.begin(), arr2_vals.end(), x);
        if (it == arr2_vals.end()) res.push_back(-1);
        else {
            int pos = it - arr2_vals.begin();
            res.push_back(sufMinIdx[pos]);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; ++i) cin >> arr1[i];

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    vector<int> ans = getFirstCompatible(arr1, arr2);
    for (int x : ans) cout << x << "\n";

    return 0;
}

