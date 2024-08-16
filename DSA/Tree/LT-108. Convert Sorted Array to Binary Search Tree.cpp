// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
class Solution {
public:
    TreeNode* helper(vector<int> v,int l,int h){
        if(l>h) return nullptr;
        int mid=l+(h-l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left=helper(v,l,mid-1);
        root->right=helper(v,mid+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
