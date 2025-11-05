
class Solution {
  public:
    int isSumProperty(Node *root) {
        return helper(root);
    }
    int helper(Node *p){
        if(!p){
            return 1;
        }
        if(!p->left && !p->right){ //the property needs to true to all the non-leaf nodes
            return 1;
        }
        int left=0,right=0; //if either of the child is missing in the sense take that as 0
        if(p->left){
            left=p->left->data;
        }
        if(p->right){
            right=p->right->data;
        }
        return (p->data==left+right) && helper(p->left) && helper(p->right);
    }
};
