//Given an 2D array which contains [price,beauty] and queries array for every queries array we have to return max possible beauty if the query exist in the price 
//store the max beauty if not then store the lesser number's maximum beauty if not lesser price exist then store 0
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());

        // Sort and store max beauty
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for (int i = 0; i < queries.size(); i++) {
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }

    int binarySearch(vector<vector<int>>& items, int targetPrice) {
        int left = 0;
        int right = items.size() - 1;
        int maxBeauty = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (items[mid][0] > targetPrice) {
                right = mid - 1;
            } else {
                // Found viable price. Keep moving to right
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return maxBeauty;
    }
};
