// 1.find connected clusters of delivery partners through restaurant hubs and return the maximum product of the two largest partner IDs in the largest cluster.
// Key approach:

// Group by Restaurant: First, I group all connections by their restaurant ID since connections are only transitive within the same restaurant.
// Build Graphs: For each restaurant, I build a graph where nodes are partners and edges represent connections through that restaurant.
// Find Connected Components: Using BFS, I find all connected components (clusters) for each restaurant.
// Calculate Products: For each cluster with size > 1, I find the two largest partner IDs and calculate their product.
// Track Maximum: I keep track of the maximum product from the largest cluster(s). If multiple clusters have the same maximum size, I take the one with the largest product.
// Time Complexity: O(R × (V + E)) where R is the number of restaurants, V is the number of vertices (partners), and E is the number of edges (connections).
// Space Complexity: O(V + E) for storing the graphs and visited sets.
// The solution handles the constraints well since partnerCount ≤ 100 and n ≤ 200

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;
int largestPartnerClusterProduct(int partnerCount, vector<int>& restaurantFrom, vector<int>& restaurantTo, vector<int>& restaurantIds) {
    // Group connections by restaurant ID
    unordered_map<int, vector<pair<int, int>>> restaurantConnections;
    
    for (int i = 0; i < restaurantFrom.size(); i++) {
        int restaurantId = restaurantIds[i];
        int from = restaurantFrom[i];
        int to = restaurantTo[i];
        
        restaurantConnections[restaurantId].push_back({from, to});
    }
    
    int maxProduct = 0;
    int maxClusterSize = 0;
    
    // Process each restaurant separately
    for (auto& [restaurantId, connections] : restaurantConnections) {
        // Build graph for this restaurant
        unordered_map<int, vector<int>> graph;
        
        for (auto& connection : connections) {
            int u = connection.first;
            int v = connection.second;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Find connected components using BFS
        unordered_set<int> visited;
        
        for (auto& [node, neighbors] : graph) {
            if (visited.find(node) == visited.end()) {
                // BFS to find connected component
                vector<int> cluster;
                queue<int> q;
                q.push(node);
                visited.insert(node);
                
                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    cluster.push_back(current);
                    
                    for (int neighbor : graph[current]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                
                // Sort cluster in descending order to get largest two elements
                if (cluster.size() > 1) {
                    sort(cluster.rbegin(), cluster.rend());
                    int currentProduct = cluster[0] * cluster[1];
                    
                    // Update result based on cluster size and product
                    if (cluster.size() > maxClusterSize) {
                        maxClusterSize = cluster.size();
                        maxProduct = currentProduct;
                    } else if (cluster.size() == maxClusterSize) {
                        if (currentProduct > maxProduct) {
                            maxProduct = currentProduct;
                        }
                    }
                }
            }
        }
    }
    
    return maxProduct;
}

int main() {
    // Test Case 1: From the first example
    int partnerCount1 = 7; // Based on partners 1,2,3,7,5,6,9,10,8
    vector<int> restaurantFrom1 = {1, 7, 5, 10, 6, 2};
    vector<int> restaurantTo1 = {2, 3, 6, 8, 9, 3};
    vector<int> restaurantIds1 = {51, 51, 51, 51, 51, 51};
    
    int result1 = largestPartnerClusterProduct(partnerCount1, restaurantFrom1, restaurantTo1, restaurantIds1);
    cout << "Test Case 1 Result: " << result1 << " (Expected: 21)" << endl;
    
    // Test Case 2: Sample Case 0
    int partnerCount2 = 6;
    vector<int> restaurantFrom2 = {1, 2, 4, 5};
    vector<int> restaurantTo2 = {2, 3, 5, 6};
    vector<int> restaurantIds2 = {10, 10, 20, 20};
    
    int result2 = largestPartnerClusterProduct(partnerCount2, restaurantFrom2, restaurantTo2, restaurantIds2);
    cout << "Test Case 2 Result: " << result2 << " (Expected: 30)" << endl;
    
    // Test Case 3: Sample Case 1
    int partnerCount3 = 3;
    vector<int> restaurantFrom3 = {1, 2};
    vector<int> restaurantTo3 = {2, 3};
    vector<int> restaurantIds3 = {15, 15};
    
    int result3 = largestPartnerClusterProduct(partnerCount3, restaurantFrom3, restaurantTo3, restaurantIds3);
    cout << "Test Case 3 Result: " << result3 << " (Expected: 6)" << endl;
    
    return 0;
}


// 2.This is a classic Sliding Window Minimum problem.
// The optimal approach uses a Deques (Double-Ended Queue) structure to efficiently find the minimum element in the current window of size groupSize in O(1) time, leading to an overall O(N) time complexity,
// where N is the number of drivers.
  #include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int selectBestDriverBlock(int groupSize, const vector<int>& availability) {
    if (groupSize == 0 || availability.empty() || groupSize > availability.size()) {
        return 0;
    }

    int n = availability.size();
    int maxEffectiveAvailability = 0;
    deque<int> windowMinIndex;

    for (int i = 0; i < n; ++i) {
        while (!windowMinIndex.empty() && availability[windowMinIndex.back()] >= availability[i]) {
            windowMinIndex.pop_back();
        }
        windowMinIndex.push_back(i);
        if (windowMinIndex.front() <= i - groupSize) {
            windowMinIndex.pop_front();
        }
        if (i >= groupSize - 1) {
            int currentMin = availability[windowMinIndex.front()];
            maxEffectiveAvailability = max(maxEffectiveAvailability, currentMin);
        }
    }
    return maxEffectiveAvailability;
}

void runExample(const string& name, int groupSize, const vector<int>& availability, int expected) {
    int result = selectBestDriverBlock(groupSize, availability);
    cout << name << " groupSize: " << groupSize << ", availability: {";
    for (size_t i = 0; i < availability.size(); ++i) {
        cout << availability[i] << (i == availability.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl;
    cout << "Expected Output: " << expected << endl;
    cout << "Actual Output: " << result << endl;
    cout << (result == expected ? "Status: Passed" : "Status: Failed") << endl;
    cout << "---------------------------------" << endl;
}

int main() {
    runExample("Sample Case 0", 2, {8, 2, 4, 6}, 4);
    runExample("Sample Case 1", 4, {3, 6, 2, 8, 7, 4, 5, 9}, 4);
    return 0;
}


// 3.This problem asks us to count the number of continuous segments (subarrays) in a sequence of rides that contain exactly a targetPremiums number of premium rides. A ride is classified as premium if its integer value is odd.
// The optimal approach for this type of subarray counting problem is the Prefix Sum (or Prefix Count) technique combined with a Hash Map (or frequency array).
// Optimal Approach: Prefix Count and Hash Map
// Transform the Array: First, convert the rideList into a binary array, say premium_count, where 1 represents a premium ride (odd value) and 0 represents a regular ride (even value).
// Calculate Prefix Counts: Compute the prefix count array, P, where P[i] is the total number of premium rides in the subarray rideList[0..i−1]. P[0]=0.
// Use the Subarray Sum Property: A subarray from index j to i−1 (i.e., rideList[j..i−1]) has a premium count of k if and only if:
// PremiumCount(j..i−1)=P[i]−P[j]=k
// We are looking for P[i]−P[j]=targetPremiums, which can be rearranged to:
// P[j]=P[i]−targetPremiums
// Count with a Hash Map: We iterate through the prefix count array P[i]. For each P[i], we look up how many times the value P[i]−targetPremiums has appeared in the prefix counts before index i. Each occurrence corresponds to a valid starting index j that forms a profitable segment ending at i−1.
// A Hash Map (prefixFreq) will store the frequency of each prefix count encountered so far.
  
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

long long countProfitableSegments(const vector<int>& rideList, int targetPremiums) {
    unordered_map<int, long long> prefixFreq;
    
    prefixFreq[0] = 1;
    
    long long currentPremiums = 0;
    long long totalCount = 0;
    
    for (int ride : rideList) {
        if (ride % 2 != 0) {
            currentPremiums++;
        }
        
        int neededPrefix = currentPremiums - targetPremiums;
        
        if (prefixFreq.count(neededPrefix)) {
            totalCount += prefixFreq[neededPrefix];
        }
        
        prefixFreq[currentPremiums]++;
    }
    
    return totalCount;
}

void runExample(const string& name, const vector<int>& rideList, int targetPremiums, long long expected) {
    long long result = countProfitableSegments(rideList, targetPremiums);
    cout << name << " Input: {";
    for(size_t i = 0; i < rideList.size(); ++i) {
        cout << rideList[i] << (i == rideList.size() - 1 ? "" : ", ");
    }
    cout << "}, Target: " << targetPremiums << endl;
    cout << "Expected Output: " << expected << endl;
    cout << "Actual Output: " << result << endl;
    cout << (result == expected ? "Status: Passed" : "Status: Failed") << endl;
    cout << "---------------------------------" << endl;
}

int main() {
    runExample("Question Example", {7, 10, 3, 6, 5}, 2, 4); 

    runExample("Sample Case 0", {8, 11, 14, 7, 4}, 1, 8); 

    runExample("Sample Case 1", {8, 11, 14, 7, 4}, 2, 4);

    return 0;
}

Link:https://chatgpt.com/share/68e401e6-dd5c-8010-903d-7f19ee6ad851
4. Unbounded knapsack . Maximize tht budget
// A budget (like knapsack capacity)
// A list of package costs (weights)
// A list of package kilometers (values)
// We can buy any package multiple times (since Uber allows buying the same ride pack any number of times) — that’s why it’s unbounded knapsack, not 0/1.

#include <bits/stdc++.h>
using namespace std;

int maximizeRideCredits(int budget, vector<int>& packageKilometers, vector<int>& packageCosts) {
    vector<int> dp(budget + 1, 0);
    int n = packageKilometers.size();

    for (int i = 1; i <= budget; i++) {
        for (int j = 0; j < n; j++) {
            if (packageCosts[j] <= i) {
                dp[i] = max(dp[i], dp[i - packageCosts[j]] + packageKilometers[j]);
            }
        }
    }

    return dp[budget];
}

int main() {
    int budget;
    cin >> budget;

    int n;
    cin >> n;
    vector<int> packageKilometers(n);
    for (int i = 0; i < n; i++)
        cin >> packageKilometers[i];

    vector<int> packageCosts(n);
    for (int i = 0; i < n; i++)
        cin >> packageCosts[i];

    cout << maximizeRideCredits(budget, packageKilometers, packageCosts) << endl;
    return 0;
}
