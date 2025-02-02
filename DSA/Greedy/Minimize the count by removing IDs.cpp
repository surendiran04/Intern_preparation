// we need to remove m ids from the array in a way such that we need less distinct Id's
//n=6,[1,1,1,2,3] ,m=2 either 2 occurence of 2 or 3 and other number can be removed so that the distinct id's become 2 in the array
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

int deleteProducts(vector<int> ids, int m) {
    unordered_map<int, int> counts;
    for (int id : ids) {
        counts[id]++;
    }

    set<int> distinct_ids;
    for (int id : ids) {
        distinct_ids.insert(id);
    }

    vector<int> frequencies;
    for (auto const& [id, count] : counts) {
        frequencies.push_back(count);
    }

    sort(frequencies.begin(), frequencies.end());

    int removed_count = 0;
    int i = 0;
    while (removed_count < m && i < frequencies.size()) {
        int to_remove = min(m - removed_count, frequencies[i]);
        removed_count += to_remove;
        if (to_remove == frequencies[i]) { // Removed all occurrences of this ID
            distinct_ids.erase(counts.begin()->first); // Remove the ID from the set
            counts.erase(counts.begin()); // Remove the ID from the counts map
        } else {
            counts[counts.begin()->first] -= to_remove; // Decrement the count of the ID
        }
        i++;
    }

    return distinct_ids.size();
}
