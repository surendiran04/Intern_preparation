#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }
};
 void print(Node* p){
        if(p){
            print(p->left);
            cout << p->data << " ";
            print(p->right);
        }
    }

class BT{
    public:
Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return root;
        } else q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode;
            return root;
        } else q.push(temp->right);
    }
    return root;
}

};

int main() {
    BST bst;
    
    bst.root = bst.insert(bst.root, 5);
    bst.root = bst.insert(bst.root, 4);
    bst.root = bst.insert(bst.root, 14);
    bst.root = bst.insert(bst.root, 7);
    bst.root = bst.insert(bst.root, 3);

    print(bst.root);
    cout<<endl;
    BT bt;
    Node* root=nullptr;
    root = bt.insert(root, 5);
    root = bt.insert(root, 4);
    root = bt.insert(root, 7);
    root = bt.insert(root, 14);
    root = bt.insert(root, 2);

    print(root);
    
    
}

