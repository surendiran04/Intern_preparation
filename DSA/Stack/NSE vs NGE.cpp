The Next greater Element NGE for an element x is the first greater element on the right side of x in the array.
The next smaller element NSE for an element x is the first smaller element on the right side of x in the array.
  
The qn is to find the next greater element's next smaller element if it doesn't exist then -1.
  
Sample Input:
   Input: 5 1 9 2 5 1 7
   output: 2 2 -1 1 -1 -1 -1


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the Next Greater Element (NGE) for each element
vector<int> findNGE(const vector<int>& arr, int n) {
    vector<int> nge(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nge;
}

// Function to find the Next Smaller Element (NSE) for each element
vector<int> findNSE(const vector<int>& arr, int n) {
    vector<int> nse(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            nse[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nse;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Step 1: Find the Next Greater Element (NGE) for each element
    vector<int> nge = findNGE(arr, n);

    // Step 2: For each element, find the Next Smaller Element (NSE) of its NGE
    vector<int> result(n, -1);
    for (int i = 0; i < n; ++i) {
        if (nge[i] != -1) {
            // Create a subarray from the position of the current element's NGE to the end of the array
            vector<int> subArr;
            for (int j = i + 1; j < n; ++j) {
                subArr.push_back(arr[j]);
            }
            vector<int> nseSubArr = findNSE(subArr, subArr.size());
            // Find the NSE for the NGE in the subarray
            for (int j = 0; j < subArr.size(); ++j) {
                if (subArr[j] == nge[i]) {
                    result[i] = nseSubArr[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
