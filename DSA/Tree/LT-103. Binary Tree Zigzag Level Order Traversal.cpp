class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int m=q.size();
            deque<int> level; //instead of deque we can also use vector
            for(int i=0;i<m;i++){
                TreeNode* p=q.front();
                q.pop();
                if(leftToRight){
                    level.push_back(p->val); //   v.push_back(temp->val);
                }
                else{
                    level.push_front(p->val); //v.insert(v.begin(), temp->val);
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            v.push_back(vector<int>(level.begin(),level.end()));
            leftToRight = !leftToRight;
        }
        return v;
    }
};
