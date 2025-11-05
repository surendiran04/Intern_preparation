Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> v;
         vector<int>x;
        getPath(root,v,x);
        return v;
    }
    void getPath(Node*p,vector<vector<int>> &v,vector<int> &x){
        if(!p){
            return;
        }
        x.push_back(p->data);
        if(!p->left && !p->right){
            v.push_back(x);
        }
        else{
            getPath(p->left,v,x);
            getPath(p->right,v,x);
        }
        x.pop_back();
    }
};
//To find a specific node path we also use the same logic
bool getPath(Node*p,vector<int>&v,int x){
  if(!p) return false;
  v.push_back(p->data);
  if(p->data==x)
     return true;
  if(getPath(p->left,v,x) || getPath(p->right,v,x))
      return true;
  v.pop_back();
  return false;
}

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,ans,temp);
        return ans;
    }
    void helper(Node* p,vector<vector<int>>& ans,vector<int> temp){ //It also works
        if(!p){
            return;
        }
        temp.push_back(p->data);
        if(!p->left && !p->right){
            ans.push_back(temp);
        }
        helper(p->left,ans,temp);
        helper(p->right,ans,temp);
    }
};
