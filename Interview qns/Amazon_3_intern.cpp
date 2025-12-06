/**
 * Finds the minimum number of security groups needed.
 *
 * security A vector of integers representing the security grade of each server.
 * return The minimum number of groups required.
 */
int findMinimumGroups(std::vector<int> security) {
    std::map<int, int> counts;
    for (int grade : security) {
        counts[grade]++;
    }

    // If there are no servers, no groups are needed.
    if (counts.empty()) {
        return 0;
    }

    int min_count = INT_MAX;
    for (auto const& [grade, count] : counts) {
        min_count = std::min(min_count, count);
    }

    for (int s = min_count; s >= 1; --s) {
        bool s_is_valid_for_all = true;

        for (auto const& [grade, count] : counts) {
  
            int m_min = (count + s) / (s + 1);

            int m_max = count / s;

            if (m_min > m_max) {

                s_is_valid_for_all = false;
                break; 
            }
        }

        if (s_is_valid_for_all) {
            int total_groups = 0;
            for (auto const& [grade, count] : counts) {
                total_groups += (count + s) / (s + 1); //ceil(count/(s+1))
            }
            return total_groups; // Return the minimal total.
        }
    }

    // This part should technically not be reached because s=1 is always valid,
    // but it's good practice for a function that returns a value.
    return -1; 
}

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief A Fenwick Tree (Binary Indexed Tree) for inversion counting.
 * It supports point updates and prefix sum queries, both in O(log n).
 */
class FenwickTree {
private:
    vector<int> bit;
    int n;

public:
    /**
     * @param size The maximum value (rank) that will be stored.
     */
    FenwickTree(int size) {
        // Size needs to be group_size, as ranks are 0 to group_size-1
        n = size;
        bit.resize(n + 1, 0);
    }

    /**
     * @brief Adds 1 to the element at index idx (0-based).
     */
    void update(int idx) {
        idx++; // Convert to 1-based indexing for BIT
        while (idx <= n) {
            bit[idx] += 1;
            idx += idx & (-idx); // Move to the next relevant index
        }
    }

    /**
     * @brief Queries the sum of elements from index 0 to idx (inclusive, 0-based).
     * @return The count of elements seen so far with rank <= idx.
     */
    int query(int idx) {
        idx++; // Convert to 1-based indexing
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx); // Move to the parent index
        }
        return sum;
    }
};

/**
 *  Finds the minimum number of swaps to sort the serial array.
 *  serial The array of serial numbers.
 *  k The swap distance.
 *  return The minimum number of operations, or -1 if impossible.
 */
long getMinSort(vector<int> serial, int k) {
    int n = serial.size();
    long total_operations = 0;

    // 1. Create the sorted version of the array
    vector<int> sorted_serial = serial;
    sort(sorted_serial.begin(), sorted_serial.end());

    // 2. Process each of the k independent groups
    for (int r = 0; r < k; ++r) {
        vector<int> current_group;
        vector<int> target_group;

        // 3. Build the current and target groups
        for (int i = r; i < n; i += k) {
            current_group.push_back(serial[i]);
            target_group.push_back(sorted_serial[i]);
        }

        int group_size = current_group.size();
        if (group_size == 0) {
            continue; // This group is empty, nothing to do
        }

        // 4. Check possibility: Does the current group contain
        //    the correct set of elements?
        vector<int> sorted_current_group = current_group;
        sort(sorted_current_group.begin(), sorted_current_group.end());

        // target_group is already sorted as it's built from sorted_serial
        if (sorted_current_group != target_group) {
            return -1; // Impossible to sort
        }

        // 5. Calculate minimum swaps (inversions)

        // 5a. Map values to their target ranks (index in the sorted group)
        map<int, int> value_to_rank;
        for (int i = 0; i < group_size; ++i) {
            value_to_rank[target_group[i]] = i;
        }

        // 5b. Create the permutation array of ranks
        vector<int> permutation;
        for (int val : current_group) {
            permutation.push_back(value_to_rank[val]);
        }

        // 5c. Count inversions in the permutation array using a Fenwick Tree
        FenwickTree ft(group_size);
        long group_inversions = 0;
        
        // Iterate through the permutation array
        for (int i = 0; i < group_size; ++i) {
            int current_rank = permutation[i];
            
            // An inversion is a number to the right that is smaller.
            // Or, a number to the left that is larger.
            // We count (total elements seen) - (elements seen <= current_rank)
            // This gives (elements seen > current_rank)
            group_inversions += (long)i - ft.query(current_rank);
            
            // Mark this rank as 'seen'
            ft.update(current_rank);
        }
        
        total_operations += group_inversions;
    }

    return total_operations;
}
// --- Main function to run test cases ---
int main() {
    // Helper function to print a vector
    auto printVector = [](const vector<int>& arr) {
        cout << "{ ";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
        }
        cout << " }";
    };

    // --- Test Case 1 (From Example) ---
    vector<int> serial1 = {6, 4, 1, 2, 3};
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "  Input: serial = "; printVector(serial1); cout << ", k = " << k1 << endl;
    cout << "  Expected: 3" << endl;
    cout << "  Actual:   " << getMinSort(serial1, k1) << endl;
    cout << "---------------------------------" << endl;

    // --- Test Case 2 (Sample Case 0) ---
    vector<int> serial2 = {7, 3, 1, 9, 28};
    int k2 = 2;
    cout << "Test Case 2 (Sample 0):" << endl;
    cout << "  Input: serial = "; printVector(serial2); cout << ", k = " << k2 << endl;
    cout << "  Expected: 1" << endl;
    cout << "  Actual:   " << getMinSort(serial2, k2) << endl;
    cout << "---------------------------------" << endl;

    // --- Test Case 3 (Sample Case 1) ---
    vector<int> serial3 = {2, 1, 4, 3, 6, 5};
    int k3 = 3;
    cout << "Test Case 3 (Sample 1):" << endl;
    cout << "  Input: serial = "; printVector(serial3); cout << ", k = " << k3 << endl;
    cout << "  Expected: -1" << endl;
    cout << "  Actual:   " << getMinSort(serial3, k3) << endl;
    cout << "---------------------------------" << endl;

    // --- Test Case 4 (Already Sorted) ---
    vector<int> serial4 = {10, 20, 30, 40, 50};
    int k4 = 2;
    cout << "Test Case 4 (Already Sorted):" << endl;
    cout << "  Input: serial = "; printVector(serial4); cout << ", k = " << k4 << endl;
    cout << "  Expected: 0" << endl;
    cout << "  Actual:   " << getMinSort(serial4, k4) << endl;
    cout << "---------------------------------" << endl;

    // --- Test Case 5 (Impossible Case) ---
    vector<int> serial5 = {1, 5, 3, 4};
    int k5 = 2;
    cout << "Test Case 5 (Impossible):" << endl;
    cout << "  Input: serial = "; printVector(serial5); cout << ", k = " << k5 << endl;
    cout << "  Expected: -1" << endl;
    cout << "  Actual:   " << getMinSort(serial5, k5) << endl;
    cout << "---------------------------------" << endl;
    
    // --- Test Case 6 (k=1, full sort) ---
    vector<int> serial6 = {5, 4, 3, 2, 1};
    int k6 = 1;
    cout << "Test Case 6 (k=1):" << endl;
    cout << "  Input: serial = "; printVector(serial6); cout << ", k = " << k6 << endl;
    cout << "  Expected: 10" << endl; // 10 inversions
    cout << "  Actual:   " << getMinSort(serial6, k6) << endl;
    cout << "---------------------------------" << endl;

    return 0;
}
