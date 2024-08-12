// Input: arr[] = [12, 34, 45, 9, 8, 90, 3]
// Output: [8, 12, 34, 90, 3, 9, 45]
class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        vector<int> even, odd;
    for (int num : arr) {
        if (num % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int index = 0;
    for (int num : even) {
        arr[index++] = num;
    }
    
    for (int num : odd) {
        arr[index++] = num;
    }
}
};
