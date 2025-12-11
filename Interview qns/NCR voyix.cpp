// There is prison and given an array x,y coordinates of theives cells make rectangle or square in shape. 
// like for every x,y there is atleast 1 [x,by] ,[ax,y] and [ax,by] and a!=1 and b!=1. So,one theif will be missing and find his coordinate.
// qns:[(1, 2), (1, 4), (3, 2)]
// Ans:(3, 4)
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMissingCell(vector<pair<int, int>> &cells) {
    unordered_map<int, int> xCount, yCount;

    for (auto &p : cells) {
        xCount[p.first]++;
        yCount[p.second]++;
    }

    int missingX = 0, missingY = 0;

    for (auto &x : xCount)
        if (x.second % 2 != 0)
            missingX = x.first;

    for (auto &y : yCount)
        if (y.second % 2 != 0)
            missingY = y.first;

    return {missingX, missingY};
}

int main() {
    int n;
    cin >> n; // number of given coordinates (3 for 1 rectangle, but can be multiple)
    vector<pair<int, int>> cells(n);
    for (int i = 0; i < n; i++) {
        cin >> cells[i].first >> cells[i].second;
    }

    pair<int, int> missing = findMissingCell(cells);
    cout << missing.first << " " << missing.second << endl;

    return 0;
}

// given n nodes and 2 arrays one is warehouse_from and another one is warehouse_to describing the connection bw the nodes and the edge is directed. 
//   we need to find the no of nodes that doesn't have any edge coming towards it.
n = 5
warehouse_from = [1, 2, 3, 3]
warehouse_to   = [2, 3, 4, 5]
1: 0
2: 1
3: 1
4: 1
5: 1
ans:1
#include <bits/stdc++.h>
using namespace std;

int countNodesWithNoIncomingEdges(int n, vector<int> &from, vector<int> &to) {
    vector<int> indegree(n + 1, 0);  // 1-based indexing

    for (int i = 0; i < from.size(); i++) {
        indegree[to[i]]++;  // increment indegree of destination
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            count++;
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;  // number of nodes and number of edges

    vector<int> from(m), to(m);
    for (int i = 0; i < m; i++) {
        cin >> from[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> to[i];
    }

    cout << countNodesWithNoIncomingEdges(n, from, to) << endl;
    return 0;
}

