class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) { //Floyd warshall algorithm 
        vector<vector<int>> cost(n,vector<int>(n,1e8));
        for(auto e:edges){
            cost[e[0]][e[1]]=e[2];
            cost[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        for(int via=0;via<n;via++){ //TC:O(n^3)
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }
        int city=0,minthres=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && cost[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minthres){
                city=i;
                minthres=cnt;
            }
        }
        return city;
    }
};

int findCity(int n, int m, vector < vector < int >> & roads, int Threshold) { //TC: O(n(n+m)logn)​ Dijkstra's method
    vector < int > num(n, 0);
    vector < pair < int, int >> adj[n];
    for (int i = 0; i < roads.size(); i++) {
        int dest1 = roads[i][0];
        int dest2 = roads[i][1];
        int cost = roads[i][2];
        adj[dest1].push_back({
            dest2,
            cost
        });
        adj[dest2].push_back({
            dest1,
            cost
        });
    }
    for (int i = 0; i < n; i++) {
        priority_queue < pair < int, int > , vector < pair < int, int >> , greater < pair < int, int >>> pq;

        vector < int > dis(n, 1e9);
        pq.push({
            0,
            i
        });
        dis[i] = 0;
        while (!pq.empty()) {
            pair < int, int > p = pq.top();
            int node = p.second;
            int dist = p.first;
            pq.pop();
            if (dist >= Threshold) {
                continue;
            }
            for (auto it: adj[node]) {
                int adj_node = it.first;
                int adj_dis = it.second;
                if (dist + adj_dis < dis[adj_node]) {
                    dis[adj_node] = dist + adj_dis;
                    pq.push({
                        dis[adj_node],
                        adj_node
                    });
                }
            }
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (dis[j] <= Threshold) {
                cnt++;
            }
        }
        num[i] = cnt;
    }
    int mn = * min_element(num.begin(), num.end());
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] == mn) {
            return i;
        }
    }
}
