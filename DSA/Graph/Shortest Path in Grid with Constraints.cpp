// You are given an n × n matrix containing only 0s and 1s, where: • 0 → water (you can move through it) • 1 → obstacle (you cannot pass through it) You are also given a value k. Starting from the top-left corner (0, 0), you need to reach the bottom-right corner (n-1, n-1) using the minimum number of moves. In one move, from your current cell (i, j), you can move up, down, left, or right — but up to k steps in that direction, stopping only before hitting an obstacle (1) or the boundary. 
//   You need to return the minimum number of moves required to reach the destination. If it’s not possible, return -1.
#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;

    q.push({0, 0});
    dist[0][0] = 0;

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= k; step++) {
                int nr = r + dr[d] * step;
                int nc = c + dc[d] * step;

                // boundary check
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) break;
                // obstacle check
                if (grid[nr][nc] == 1) break;
                // already reached with fewer moves
                if (dist[nr][nc] < dist[r][c] + 1) break;

                if (dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1},
        {0,0,0},
        {1,0,0}
    };
    int k = 2;
    cout << minMoves(grid, k);
}

