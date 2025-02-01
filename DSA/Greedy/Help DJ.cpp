// DJ Varun works in a club and plays cool songs. He has N disks of different albums (each of equal radius). 
// Every disk has a distinct number out of 1 to N associated with it. Disks are placed one over the other in a single pile.
// Varun wants to sort this pile of disks in increasing order from top to bottom. However, he has a special method for doing this: in a single step, he can only choose one disk out of the pile and put it at the top.
// The task is to determine the minimum number of steps needed to sort the pile.
// Here, consider the rightmost element to be the top.If it is impossible to sort the pile, output -1.
// Input
// The first line contains integer N, the size of the array, followed by an array of size N containing integers 1 to N in any random order, 
// which shows the position of disks from top to bottom.
// 1 ≤ N ≤ 106
// Output
// Print the minimum number of steps needed to sort the pile. If it cannot be sorted, return -1.
// Examples
// Input
// 5
// 5 4 3 2 1
// Output
// 0
// Explanation:
// The disks are already sorted from top to bottom. No steps are needed.
// Input
// 5
// 1 2 3 4 5
// Output
// 4
// Explanation:
// Each disk must be picked up one by one and placed on top until they are sorted in increasing order. For example:
// Step 1: Pick disk 4 and move it to the top.
// Disk Pile becomes 1 2 3 5 4
// Step 2: Pick disk 3 and move it to the top.
// Disk Pile becomes 1 2 5 4 3
// Step 3: Pick disk 2 and move it to the top.
// Disk Pile becomes 1 5 4 3 2
// Step 4: Pick disk 1 and move it to the top.
// Disk Pile becomes 5 4 3 2 1
// Total steps = 4.
  
// Input
// 5
// 1 5 3 4 2
// Output
// 3
// Explanation:
// To sort the pile:
// Step 1: Pick disk 3 and move it to the top.
// Disk Pile becomes 1 5 4 2 3
// Step 2: Pick disk 2 and move it to the top.
// Disk Pile becomes 1 5 4 3 2
// Step 3: Pick disk 1 and move it to the top.
// Disk Pile becomes 5 4 3 2 1
// Total steps = 3.
  
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minStepsToSortDisks(int N, vector<int>& disks) {
    // Check if the array is already sorted in decreasing order (desired order)
    if (is_sorted(disks.begin(), disks.end(), greater<int>())) {
        return 0;
    }

    int target = N;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (disks[i] == target) {
            count++;
            target--;
        }
    }

    return N - count;
}

int main() {
    int N;
    cin >> N;
    vector<int> disks(N);
    for (int i = 0; i < N; i++) {
        cin >> disks[i];
    }
    cout << minStepsToSortDisks(N, disks) << endl;
    return 0;
}
