https://www.geeksforgeeks.org/dsa/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/

vector<int> maxOfMin(vector<int>& arr) { //Brute force
    int n = arr.size();
    vector<int> res(n);
    
    // for each window size k
    for (int k = 1; k <= n; k++) {
        int maxMin = INT_MIN;
        
        // slide window of size k
        
        for (int i = 0; i <= n - k; i++) {
            int minval = INT_MAX;
            
            // find minimum in current window
            for (int j = i; j < i + k; j++) {
                minval = min(minval, arr[j]);
            }
            
            maxMin = max(maxMin, minval);
        }
        res[k - 1] = maxMin;
    }
    return res;
}
// arr = 10,20,30 
//   k=1 [10],[20],[30]  max=30
//   k=2 [10,20],[20,30] max=20
//   k=3 [10,20,30]   max=10

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxOfMin(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n), len(n + 1, 0);
    stack<int> st;

    // find window sizes for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            int top = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            int windowSize = right - left - 1;
            len[windowSize] = max(len[windowSize], arr[top]);
        }
        st.push(i);
    }

    // process remaining elements in stack
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = n;
        int windowSize = right - left - 1;
        len[windowSize] = max(len[windowSize], arr[top]);
    }

    for (int i = 1; i <= n; i++) {
        res[i - 1] = len[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    return res;
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> res = maxOfMin(arr);
    for (int val : res) cout << val << " ";
    cout << endl;
    return 0;
}
