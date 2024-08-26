class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int postIndex=postorder.size()-1;
        return generateBT(postorder,inorder,postIndex,0,postorder.size()-1);
    }
    TreeNode* generateBT(vector<int> postorder, vector<int> inorder,int &postIndex,int start,int end){
        if(start>end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[postIndex--]);
        if(start==end){
            return node;
        }
        int splitIndex=searchInorder(inorder,start,end,node->val);
        node->right=generateBT(postorder,inorder,postIndex,splitIndex+1,end);
        node->left=generateBT(postorder,inorder,postIndex,start,splitIndex-1);
        return node;
    }
    int searchInorder(vector<int> arr,int s,int e,int val){
        for(int i=s;i<=e;i++){
            if(arr[i]==val)
                return i;
        }
        return -1;
    }
};
