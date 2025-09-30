#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort.
// It considers the last element as pivot
// and moves all smaller elements to the left of
// it and greater elements to the right.
int partition(vector<int>& arr, int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

// This function returns the k-th smallest 
// element in arr[l..r] using QuickSort-based method.
// ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT.
int kthSmallest(vector<int>& arr, int l, int r, int k) {
  
    // If k is smaller than the number of elements
    // in the array.
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around the last 
        // element and get the position of the pivot 
        // element in the sorted array.
        int index = partition(arr, l, r);

        // If position is the same as k.
        if (index - l == k - 1)
            return arr[index];

        // If position is more, recur for the left subarray.
        if (index - l > k - 1) 
            return kthSmallest(arr, l, index - 1, k);

        // Else recur for the right subarray.
        return kthSmallest(arr, index + 1, r, 
                            k - index + l - 1);
    }

    // If k is more than the number of elements in the array.
    return INT_MAX;
}

// Driver program to test the above methods.
int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int n = arr.size();
    int k = 3;
    cout << "K-th smallest element is " 
         << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
