Link: https://www.geeksforgeeks.org/dsa/shortest-path-by-removing-k-walls/ LT-1293. Shortest Path in a Grid with Obstacles Elimination
// Given a 2D binary matrix of size N * M, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer K.
// You can walk up, down, left, or right. Given that you can remove up to K walls, 
// return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (N-1, M-1). 

// Input: N = 3, M = 3, K = 1
// mat = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}}
// Output: 4

// Input: N = 2, M = 2, K = 0
// mat[] = {{0, 1}, {1, 0}}
// Output: -1

#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, dist, walls;
};

vector<vector<int>> grid;
int n, m, K;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int shortestPathWithWalls() {
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(K+1, false)));

    queue<State> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.x == n-1 && cur.y == m-1) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newWalls = cur.walls + (grid[nx][ny] == 1);
                if (newWalls <= K && !visited[nx][ny][newWalls]) {
                    visited[nx][ny][newWalls] = true;
                    q.push({nx, ny, cur.dist + 1, newWalls});
                }
            }
        }
    }

    return -1;
}

int main() {
    grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    n = grid.size();
    m = grid[0].size();
    K = 2;

    int ans = shortestPathWithWalls();
    if (ans != -1)
        cout << "Shortest path length: " << ans << "\n";
    else
        cout << "No path exists\n";

    return 0;
}

------------------------------------------------------------------------------------------------------------------------
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Example 1:
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
// Example 2:

// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4
// Example 3:

// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1
 #include <bits/stdc++.h>
using namespace std;

vector<int> weights;
int D;

bool canShip(int capacity) {
    int daysNeeded = 1, currentLoad = 0;
    for (int w : weights) {
        if (currentLoad + w > capacity) {
            daysNeeded++;
            currentLoad = 0;
        }
        currentLoad += w;
    }
    return daysNeeded <= D;
}

int shipWithinDays() {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(mid)) {
            ans = mid;
            high = mid - 1; // try smaller capacity
        } else {
            low = mid + 1;  // need bigger capacity
        }
    }
    return ans;
}

int main() {
    weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    D = 5;

    cout << "Minimum capacity to ship within " << D << " days: " << shipWithinDays() << "\n";
    return 0;
}
