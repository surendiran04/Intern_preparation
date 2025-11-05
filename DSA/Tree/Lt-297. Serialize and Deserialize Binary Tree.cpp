class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s="";
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node==nullptr){
                s+="#,";
            }else{
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="#"){
            return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();q.pop();
            if (!getline(s, str, ',')) break;
            if(str=="#"){
                node->left=nullptr;
            }else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s, str, ',');
            if(str=="#"){
                node->right=nullptr;
            }else{
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }

        }
        return root;
    }
};
