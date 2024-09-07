#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int units, int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost) {
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        // Total amount of metal i needed to produce 'units' units of alloy
        int required = units * composition[i];
        if (required > stock[i]) {
            // If stock is not enough, calculate how much more we need to buy
            int buy = required - stock[i];
            totalCost += buy * cost[i];
        }

        // If the total cost exceeds the budget, return false
        if (totalCost > budget) {
            return false;
        }
    }

    // Return true if we can afford all the metals within the budget
    return totalCost <= budget;
}

int maxAlloyUnits(int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost) {
    int left = 0, right = 1e6; // Assume a large upper limit for the possible number of units
    int maxUnits = 0;

    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(mid, n, budget, composition, stock, cost)) {
            // If it's possible to produce 'mid' units, check for more
            maxUnits = mid;
            left = mid + 1;
        } else {
            // Otherwise, reduce the number of units
            right = mid - 1;
        }
    }

    return maxUnits;
}

int main() {
    // Example 1:
    int n1 = 3, budget1 = 14;
    vector<int> composition1 = {2, 1, 2};
    vector<int> stock1 = {1, 0, 0};
    vector<int> cost1 = {2, 2, 1};
    cout << "Maximum number of alloy units that can be produced = " << maxAlloyUnits(n1, budget1, composition1, stock1, cost1) << endl;

    // Example 2:
    int n2 = 4, budget2 = 45;
    vector<int> composition2 = {3, 2, 3, 1};
    vector<int> stock2 = {2, 6, 5, 4};
    vector<int> cost2 = {4, 2, 1, 3};
    cout << "Maximum number of alloy units that can be produced = " << maxAlloyUnits(n2, budget2, composition2, stock2, cost2) << endl;

    return 0;
}
