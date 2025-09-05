#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class MaxHeap {   // If we change the > to < then it will act as a MinHeap
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1, right = 2 * i + 2, largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap mx;
    mx.push(1);
    mx.push(3);
    mx.push(2);
    mx.push(4);
    mx.push(6);
    mx.push(5);
    while(!mx.empty()){
        cout<<mx.top()<<" ";
        mx.pop();
    }
    return 0;
}
