class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        return generateBT(preorder,inorder,preIndex,0,preorder.size()-1);
    }
    TreeNode* generateBT(vector<int> preorder, vector<int> inorder,int &preIndex,int start,int end){
        
        if(start>end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        if(start==end){
            return node;
        }
        int splitIndex=searchInorder(inorder,start,end,node->val);
        node->left=generateBT(preorder,inorder,preIndex,start,splitIndex-1);
        node->right=generateBT(preorder,inorder,preIndex,splitIndex+1,end);
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
