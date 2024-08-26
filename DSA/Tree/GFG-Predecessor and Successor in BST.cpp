class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if (!root) return;

        // Find predecessor
        Node* curr = root;
        while (curr) {
            if (curr->key < key) {
                pre = curr; // Potential predecessor
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Find successor
        curr = root;
        while (curr) {
            if (curr->key > key) {
                suc = curr; // Potential successor
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
};
