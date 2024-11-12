class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        vector<pair<int, int>> max_beauties;
        int max_beauty = 0;
        
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            max_beauty = max(max_beauty, beauty);
            max_beauties.push_back({price, max_beauty});
        }
        vector<int> result;
        for (int query : queries) {
            auto it = upper_bound(max_beauties.begin(), max_beauties.end(), make_pair(query, INT_MAX));
            if (it == max_beauties.begin()) {
                result.push_back(0);
            } else {
                result.push_back(prev(it)->second); 
            }
        }
        
        return result;
    }
};
