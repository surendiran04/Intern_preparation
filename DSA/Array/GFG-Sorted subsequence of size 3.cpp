// Sorted subsequence of size 3
// Difficulty: MediumAccuracy: 25.95%Submissions: 81K+Points: 4Average Time: 20m
// You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.
#include <bits/stdc++.h>
using namespace std;

// A function to find a sorted sub-sequence of size 3
vector<int> find3Numbers(vector<int> &arr)
{
    int n = arr.size();

    // Fill smaller[] such that smaller[i] stores the
    // index of a smaller element on the left side
    vector<int> smaller(n, -1);
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[min])
            min = i;
        else
            smaller[i] = min;
    }

    // Fill greater[] such that greater[i] stores the
    // index of a greater element on the right side
    vector<int> greater(n, -1);
    int max = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
            max = i;
        else
            greater[i] = max;
    }
    for(int i=0;i<n-1;i++){
        cout<<smaller[i]<<" "<<greater[i]<<endl;
    }
    // Find the triplet
    for (int i = 0; i < n; i++)
    {
        if (smaller[i] != -1 && greater[i] != -1)
            return {arr[smaller[i]], arr[i], arr[greater[i]]};
    }

    // If no such triplet is found, return an empty vector
    return {};
}

// Driver code
int main()
{
    vector<int> arr = {12, 11, 10, 5, 6, 2, 30};
    vector<int> res = find3Numbers(arr);
    for (int x : res)
        cout << x << " ";
    return 0;
}
