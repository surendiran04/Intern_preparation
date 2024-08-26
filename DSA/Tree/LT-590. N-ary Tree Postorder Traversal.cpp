class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        stack<Node*> st;
        vector<int> v;
        unordered_map<Node*,int> map; //map takes care of each node's children size
        st.push(root);
        while(!st.empty()){
            Node* t=st.top();
            if(map[t]<t->children.size()){
                Node* child=t->children[map[t]];
                map[t]++;
                st.push(child);
            }else{
                v.push_back(t->val);
                st.pop();
            }
        }
        return v;
    }
};
