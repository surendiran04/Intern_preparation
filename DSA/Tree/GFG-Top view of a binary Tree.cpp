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
            pair<Node*,int>p=q.front();
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
