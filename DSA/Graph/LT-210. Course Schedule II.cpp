class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector < vector < int >> adj(numCourses);
        for (auto e: prerequisites) {
            adj[e[0]].push_back(e[1]);
        }
        vector < int > indegree(numCourses, 0);
        for (int u = 0; u < numCourses; u++) {
            for (int v: adj[u]) {
                indegree[v]++;
            }
        }
        queue < int > q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
       vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node); 
            for (int v: adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(topo.size()!=numCourses){ //Impossible 
            return {};
        }
        reverse(begin(topo),end(topo));
        return topo;
    }
};
