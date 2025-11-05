class Solution
{
    public:
    vector<int> topView(Node *root)
    {

        if(!root) return {};
        vector<int> v;
        queue<pair<Node*,int>>q;
        map<int,int> map;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>p=q.front(); //TC: O(Nlogn) since using map 
            q.pop();
            int hd=p.second;
            Node* node=p.first;
            if(map.find(hd)==map.end()){
                map[hd]=node->data;
            }
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        for(const auto x:map){
            v.push_back(x.second);
        }
        return v;
    }

};



class Solution {
public:
    vector<int> topView(Node* root) { //TC:O(N)
        if (!root) return {};

        // Queue for BFS: stores (node, horizontal distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        // unordered_map to store first node for each horizontal distance
        unordered_map<int, int> mp;
        int minHd = 0, maxHd = 0;

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Store the first node encountered at this horizontal distance
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            // Track range of horizontal distances
            minHd = min(minHd, hd);
            maxHd = max(maxHd, hd);

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Construct result using known range of HDs
        vector<int> ans;
        for (int hd = minHd; hd <= maxHd; hd++) {
            ans.push_back(mp[hd]);
        }

        return ans;
    }
};

