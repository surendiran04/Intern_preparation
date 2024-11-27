class Solution {
public:
    // Helper function to perform BFS and find the number of edges in the
    // shortest path from node 0 to node n-1
    int bfs(int n, vector<vector<int>>& adjList) {
        vector<bool> visited(n, false);
        queue<int> nodeQueue;
        // Start BFS from node 0
        nodeQueue.push(0);
        visited[0] = true;

        // Track the number of nodes in the current layer and the next layer
        int currentLayerNodeCount = 1;
        int nextLayerNodeCount = 0;
        // Initialize layers explored count
        int layersExplored = 0;

        // Perform BFS until the queue is empty
        while (!nodeQueue.empty()) {
            // Process nodes in the current layer
            for (int i = 0; i < currentLayerNodeCount; ++i) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();

                // Check if we reached the destination node
                if (currentNode == n - 1) {
                    return layersExplored;  // Return the number of edges in the
                                            // shortest path
                }

                // Explore all adjacent nodes
                for (auto neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    nodeQueue.push(
                        neighbor);  // Add neighbor to the queue for exploration
                    nextLayerNodeCount++;  // Increment the count of nodes in
                                           // the next layer
                    visited[neighbor] = true;
                }
            }

            // Move to the next layer
            currentLayerNodeCount = nextLayerNodeCount;
            nextLayerNodeCount = 0;  // Reset next layer count
            layersExplored++;  // Increment the layer count after processing the
                               // current layer
        }

        return -1;  // Algorithm will never this point
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        // Process each query to add new roads
        for (auto& road : queries) {
            int u = road[0];
            int v = road[1];
            adjList[u].push_back(v);  // Add road from u to v
            // Perform BFS to find the shortest path after adding the new road
            answer.push_back(bfs(n, adjList));
        }

        return answer;
    }
};

