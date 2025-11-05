class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {  //T(n) - O(NlogN) ,S(n) - O(N)
        if (!root) return {};
        map<int, map<int, multiset<int>>> nodes; //multiset automatically sorts
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}}); 
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop(); 
            TreeNode* node = p.first;
            int hd = p.second.first;
            int depth = p.second.second;
            nodes[hd][depth].insert(node->val); //since the for each depth the nodes->val are added
            if (node->left) {
                q.push({node->left, {hd - 1, depth + 1}});
            }
            if (node->right) {
                q.push({node->right, {hd + 1, depth + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto hd_map : nodes) { 
            vector<int> col;
            for (auto depth_map : hd_map.second) {  //since it is a ordered map it takes care of order of the left nodes
                col.insert(col.end(), depth_map.second.begin(), depth_map.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};
class Solution { //passes 20/35 casese
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> v;
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>> map;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int>p=q.front();
            q.pop();
            int hd=p.second;
            TreeNode* node=p.first;
            map[hd].push_back(node->val);
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        vector<int> ans;
        for(const auto x:map){
            ans=x.second;
            sort(ans.begin()+1,ans.end()); //sorting is not based on each depth that is the problem
            v.push_back(ans);
            ans.clear();
        }
        return v;
    }
};
