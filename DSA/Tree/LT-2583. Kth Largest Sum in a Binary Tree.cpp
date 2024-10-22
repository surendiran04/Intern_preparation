//Return K largest level's sum in a binary tree if there are less than k levels then return -1
// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {  // also use min - heap ans pop out while pushing elements if pq.size()>k atlast pq.size()<k?-1:pq.top()
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        long long sum=0;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                TreeNode* p=q.front();
                q.pop();
                sum+=p->val;
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }

            }
            ans.push_back(sum);
            sum=0;
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return n>=k?ans[n-k]:-1;
    }
};
