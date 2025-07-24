// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:
// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,1,2,3,4,5], k = 4, x = -1
// Output: [1,1,2,3]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) { //finding the starting element window
        int l=0,r=arr.size()-k,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};

      /**
     *  Sort with a Custom Comparator
     * Time: O(N log N), Space: O(N) or O(k)
     */

     std::stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return std::abs(a - x) < std::abs(b - x);
        });

        // The first k elements are now the closest ones, but not necessarily sorted.
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(arr[i]);
        }

        // Sort the final result in ascending order.
        std::sort(result.begin(), result.end());
        return result;
    }

    /**
       Using a Max-Heap (Priority Queue)
     * Time: O(N log k), Space: O(k)
     */

        std::priority_queue<std::pair<int, int>> maxHeap;

        for (int num : arr) {
            int dist = std::abs(num - x);
            maxHeap.push({dist, num});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        std::vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        // The elements from the heap are not in sorted order, so we sort them.
        std::sort(result.begin(), result.end());
        return result;
