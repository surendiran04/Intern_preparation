class Solution {
public:
    vector<int> preorderTraversal(TreeNode* p) {
        vector<int> v;
        stack<TreeNode*> st;
        while(p!=nullptr || !st.empty()){
            if(p){
                v.push_back(p->val);
                st.push(p);
                p=p->left;
            }
            else{
                p=st.top();
                st.pop();
                p=p->right;
            }
        }
        return v;
    }
};
