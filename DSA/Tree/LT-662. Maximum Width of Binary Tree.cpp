Input: root = [1,3,2,5,3,null,9]
Output: 4
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes
class Solution {
public:
    int widthOfBinaryTree(TreeNode* p) {
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        q.push({p,0});
        while(!q.empty()){
            int n=q.size();
            int m=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                long c=q.front().second-m;  //making the every level's first node as 0 and last node no of nodes
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=c;
                if(i==n-1) last=c;
                if(node->left){
                    q.push({node->left,c*2+1});
                }
                 if(node->right){
                    q.push({node->right,c*2+2});
                }
            }
            ans=max(ans,last-first+1); //here we don't first since it is always 0 
        }
        return ans;
    }
};
