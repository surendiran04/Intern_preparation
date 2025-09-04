#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int partition1(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = 0,j=high;
    while(i<j){
        while(i<high && arr[i]<=pivot){
            i++;
        }
        while(j>low && arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition1(arr, low, high);

        quickSort(arr, low, pi - 1);  // left part
        quickSort(arr, pi + 1, high); // right part
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 5,9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
