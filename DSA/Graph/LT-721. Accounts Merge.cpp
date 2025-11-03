class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> acc;
        DSU ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (acc.find(mail) == acc.end()) {
                    acc[mail] = i;
                } else {
                    ds.unionBySize(i, acc[mail]);
                }
            }
        }

        vector<vector<string>> mails(n);
        for (auto &a : acc) {
            string mail = a.first;
            int node = ds.findParent(a.second);
            mails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mails[i].empty()) continue;
            sort(mails[i].begin(), mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &s : mails[i]) temp.push_back(s);
            ans.push_back(temp);
        }

        return ans;
    }
};
