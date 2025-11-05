class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) { //Anti-clock wise direction
        vector<int> res;
        res.push_back(root->data);
        if(isLeaf(root)){
            return res;
        }
        addleft(root,res);         //If asked clock wise direction change left right order
        addleaves(root,res);
        addright(root,res);
        
        return res;
    }
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void addleft(Node* root,vector<int>& res) {
        Node* t=root->left;
        while(t){
            if(!isLeaf(t)){
                res.push_back(t->data);
            }
            if(t->left){
                t=t->left;
            }else{
                t=t->right;
            }
        }
    }
   void addright(Node* root,vector<int>& res) {
        Node* t=root->right;
        vector<int> temp;
        while(t){
            if(!isLeaf(t)){
                temp.push_back(t->data);
            }
            if(t->right){
                t=t->right;
            }else{
                t=t->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
        
    }
    void addleaves(Node *root,vector<int>& res) {
          if(!root){
              return;
          }
          addleaves(root->left,res);
          if(isLeaf(root)){
              res.push_back(root->data);
          }
          addleaves(root->right,res);
    }
};
