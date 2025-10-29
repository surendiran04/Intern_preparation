// I was asked a Binary Tree based Question where in a Binary Tree has all the float64 values.
// We had to do the following operations:
// a. replace node->val with its reciprocal
// b. swap the left and right nodes of the tree**(not swapping values)**
// c. if the node->val is the arithematic mode(i.e most repeated value in the tree) then remove its subtree and that node
// Time Complexity : O(n) (O(n) in all the functions individually)
// Space Complexity : O(n) (using just the map)
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    double val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(double x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* twisty(TreeNode* root) {
        if (!root) return nullptr;
        unordered_map<double,int> freq;
        countFreq(root, freq);
        double mode = root->val;
        int maxf = 0;
        for (auto &p : freq) {
            if (p.second > maxf) {
                maxf = p.second;
                mode = p.first;
            }
        }
        return transform(root, mode);
    }

private:
    void countFreq(TreeNode* node, unordered_map<double,int>& freq) {
        if (!node) return;
        freq[node->val]++;
        countFreq(node->left, freq);
        countFreq(node->right, freq);
    }

    TreeNode* transform(TreeNode* node, double mode) {
        if (!node) return nullptr;
        if (node->val == mode) {
            freeTree(node);
            return nullptr;
        }
        swap(node->left, node->right);
        node->val = 1.0 / node->val; // here he asked to add check of non-zero division
        node->left = transform(node->left, mode);
        node->right = transform(node->right, mode);
        return node;
    }

    void freeTree(TreeNode* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
};
