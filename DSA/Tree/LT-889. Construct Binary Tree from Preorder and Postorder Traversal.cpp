// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
class Solution {
public:
   TreeNode*build(vector<int>&pre,int preLow,int preHigh,vector<int>&post,int postLow,int postHigh){
        // base case
        if(preLow > preHigh || postLow > postHigh) return NULL; 
        TreeNode*root=new TreeNode(pre[preLow]);
        // when there is only one node
        if(preLow == preHigh) return root;
        int i=postLow;
        // find the 2nd element of preOrder in postOrder 
        while(i <= postHigh){
            if(post[i]==pre[preLow+1]) break;
            i++;
        }
        int leftCount = i-postLow;
        // recursion part of left & right subtree
        root->left = build(pre, preLow+1, preLow+leftCount+1, post, postLow, i);
        root->right = build(pre, preLow+leftCount+2, preHigh, post, i+1, postHigh);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
    }
};
