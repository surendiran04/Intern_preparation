//On 1 bomb detonation how much more bombs can detonate - from which bomb node we can traverse max no of nodes
#define ll long long int
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) { //O(N^3)
        int n = bombs.size();
        vector<vector<int>> gr(n);
        for (int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            ll r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    ll x = abs(x1 - bombs[j][0]);
                    ll y = abs(y1 - bombs[j][1]);
                    if (x * x + y * y <= r1 * r1) {
                        gr[i].push_back(j);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            vector<bool> vis(n, false);
            // for(int k=0;k<gr[i].size();k++){
            //     cout<<gr[i][k]<<" ";
            // }
            // cout<<"\n";
            bfs(vis, gr, i, cnt); //we choose any dfs or bfs
            ans = max(cnt, ans);
        }
        return ans;
    }
    void dfs(vector<bool>& vis, vector<vector<int>>& gr, int& u, int& c) {
        c++;
        vis[u] = true;
        for (int v = 0; v < gr[u].size(); v++) {
            if (!vis[gr[u][v]]) {
                dfs(vis, gr, gr[u][v], c); 
            }
        }
    }
    void bfs(vector<bool>& vis, vector<vector<int>>& gr, int& u, int& c) {
        queue<int> q;
        q.push(u);
        vis[u] = true;
        while (!q.empty()) {
            int s = q.size();
            for (int v = 0; v < s; v++) {
                int x = q.front();
                q.pop();
                c++;
                for (auto p : gr[x]) {
                    if (!vis[p]) {
                        q.push(p);
                        vis[p] = true;
                    }
                }
            }
        }
    }
};
