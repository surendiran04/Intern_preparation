class Solution {
public:
    int maxDepth(Node* root) {
         if (root == nullptr) {
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        int ans=0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                for(Node* v:node->children) {
                    q.push(v);
                }
            }
            depth++;
            ans=max(ans,depth);
        }
        return ans;
    }
};
