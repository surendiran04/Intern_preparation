// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]  ans:bdac
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        // Mark all characters that appear
        for (string &w : words) {
            for (char c : w) {
                present[c - 'a'] = 1;
            }
        }

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];

            // Invalid case: prefix issue
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
                return "";

            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topo_sort(adj, present);
        if (topo.empty()) return "";

        string ans = "";
        for (int i : topo)
            ans += char(i + 'a');
        return ans;
    }

    vector<int> topo_sort(vector<vector<int>> &adj, vector<int> &present) {
        vector<int> indegree(26, 0);

        for (int u = 0; u < 26; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check for cycle
        int countChars = 0;
        for (int i = 0; i < 26; i++) if (present[i]) countChars++;

        if ((int)topo.size() != countChars) return {};
        return topo;
    }
};
