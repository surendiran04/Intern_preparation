// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
  
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int &a,int &b){
            if(freq[a]==freq[b]){
                return a<b;
            }
            return freq[a]>freq[b];
        });
        vector<int> res;
        int i=0;
        while(k>0 && i<n){
            if(res.empty() || (!res.empty() && res.back()!=nums[i])){  // No duplicates needs to be entered
                res.push_back(nums[i]);
                k--;
            }
            i++;
        }
        return res;
    }
};

class Solution {   //return the k number of elements which has the max frequency
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { // T(n) = O(n + k)  Bucket dort
        unordered_map<int,int> map;
        vector<int> res;
        for(int num:nums){   //found the count every elements
            map[num]++;
        }
        int n=nums.size();
        vector<vector<int>> v(n+1);
        for(const pair<int, int>& x : map){   //Making the count as index and adding elements in it
            v[x.second].push_back(x.first);
        }
        for(int i=n;i>0 && k;i--){    
            if(!v[i].empty()){
                for(const int& m : v[i]){  //once we found the top k elements loop breaks
                     res.push_back(m);
                     k--;
                }   
            }
        }
        return res;
    }
};

#include <iostream>  //appraoch using priority queue and implementing min-heap
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {   //T(n) = O(n log n) 
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // Create a min-heap (priority queue) based on frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& entry : freq) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only the top k frequent elements
            }
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end()); // Reverse to get the highest frequency elements first
        return res;
    }
};
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>  //another approach using sorting the count
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b) {  //T(n) = O(n log n) 
    // Sort by frequency (decreasing order)
    return a.second > b.second;
}
void sortByFrequency(vector<int>& arr) {
    unordered_map<int, int> freq;
    // Calculate the frequency
    for (int num : arr) {
        freq[num]++;
    }
    // Convert map to vector of pairs
    vector<pair<int, int>> freqPairs;
    for (auto& entry : freq) {
        freqPairs.push_back(entry);
    }
    // Sort the vector of pairs
    sort(freqPairs.begin(), freqPairs.end(), compare);
    // Reconstruct the sorted array
    int idx = 0;
    for (auto& pair : freqPairs) {
        int num = pair.first;
        int count = pair.second;
        while (count--) {
            arr[idx++] = num;
        }
    }
}
int main() {
    vector<int> arr = {1, 5, 3, 3, 2, 3, 4, 3, 3, 2, 4, 4, 4};
    // Sort the array based on frequency
    sortByFrequency(arr);
    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

