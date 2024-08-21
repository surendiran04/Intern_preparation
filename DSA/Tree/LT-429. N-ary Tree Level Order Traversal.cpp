class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int m=q.size();
            vector<int> ans;
            for(int i=0;i<m;i++){
            Node* root=q.front();
            q.pop();
            ans.push_back(root->val);
            for(Node* child:root->children){
                q.push(child);
            }
            }
            v.push_back(ans);
            ans.clear();
        }
        return v;
    }
};
