class Solution {
public:
    vector<int> postorderTraversal(TreeNode* p) { //TC,SC:O(n)
        stack<pair<TreeNode*,bool>> st;
        vector<int> v;
        pair<TreeNode*,bool> temp;
        while(p!=nullptr || !st.empty()){
            if(p!=nullptr){
                st.push({p,false});
                p=p->left;
            }
            else{
                temp=st.top();
                st.pop();
                if(temp.second){ //instead of making it minus we are using a extra bool to notice whether it is visited or not
                    v.push_back(temp.first->val);
                    p=nullptr;
                }else{
                    st.push({temp.first,true});
                    p=temp.first->right;
                }
            }
        }
        return v;
    }
};
class Solution { //this is relatively faster 100%
public:
    vector<int> postorderTraversal(TreeNode* p) {
        vector<int> v;
        stack<long int> stk;
        long int temp;
       while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->left;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){ //to make the already visited
                stk.emplace(-temp);
                p = ((TreeNode*)temp)->right;
            } else {
                v.push_back(((TreeNode*)(-1 * temp))->val);
                p = nullptr;
            }
        }
    }
        return v;
    }
};
