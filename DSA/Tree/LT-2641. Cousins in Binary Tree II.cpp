// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.
// Return the root of the modified tree.
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) { //2 BFS
        if (!root)
            return nullptr;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                TreeNode* p = q.front();
                q.pop();
                sum += p->val;
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            v.push_back(sum);
            sum = 0;
        }
        int levelsum = 0;
        q.push(root);
        root->val = 0;
        int depth=1;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                TreeNode* p = q.front();
                q.pop();
                levelsum = (p->left?p->left->val:0)+(p->right?p->right->val:0);
                if (p->left) {
                    p->left->val=v[depth]-levelsum;
                    q.push(p->left);
                }
                if (p->right) {
                    p->right->val=v[depth]-levelsum;
                    q.push(p->right);
                }
            }
            depth++;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) { //1 BFS
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int previousLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Update node value to cousin sum.
                currentNode->val = previousLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr) {
                    currentLevelSum += currentNode->left->val;  // Accumulate current level sum.
                    currentNode->left->val = siblingSum;  // Update left child's value.
                    nodeQueue.push(currentNode->left);  // Add to queue for next level.
                }
                if (currentNode->right != nullptr) {
                    currentLevelSum += currentNode->right->val;  // Accumulate current level sum.
                    currentNode->right->val = siblingSum;  // Update right child's value.
                    nodeQueue.push(currentNode->right);  // Add to queue for next level.
                }
            }

            previousLevelSum = currentLevelSum;  // Update previous level sum for next iteration.
        }
        return root;
    }
};
