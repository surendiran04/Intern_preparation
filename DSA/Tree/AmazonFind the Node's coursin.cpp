#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	Node *left, *right;
};

// A utility function to create a new 
// Binary Tree Node
Node *newNode(int item)
{
	Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* It returns level of the node if it is
present in tree, otherwise returns 0.*/
int getLevel(Node *root, Node *node, int level)
{
	
	// base cases
	if (root == NULL)
		return 0;
	if (root == node)
		return level;

	// If node is present in left subtree
	int downlevel = getLevel(root->left,node, level + 1);
	if (downlevel != 0)
		return downlevel;

	// If node is not present in left subtree
	return getLevel(root->right, node, level + 1);
}
void printGivenLevel(Node* root, Node *node, int level)
{
	if (root == NULL || level < 2)
		return;
	if (level == 2)
	{
		if (root->left == node || root->right == node)
			return;
		if (root->left)
			cout << root->left->data << " ";
		if (root->right)
			cout << root->right->data;
	}
	else if (level > 2)
	{
		printGivenLevel(root->left, node, level - 1);
		printGivenLevel(root->right, node, level - 1);
	}
}
void printCousins(Node *root, Node *node)
{
	int level = getLevel(root, node, 1);

	printGivenLevel(root, node, level);
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(15);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	printCousins(root, root->left->right);

	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
};

// A utility function to create a new Binary Tree Node
Node *newNode(int item) {
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to print cousins of the given node
void printCousins(Node* root, Node* node) {
    if (!root || root == node) {
        cout << "No cousins" << endl;
        return;
    }

    // Using a queue for BFS
    queue<Node*> q;
    q.push(root);
    bool found = false;

    while (!q.empty() && !found) {
        int size = q.size();

        // Process each node of the current level
        for (int i = 0; i < size; ++i) {
            Node* current = q.front();
            q.pop();

            // Check if the current node is a parent of the target node
            if ((current->left == node) || (current->right == node)) {
                found = true; // Mark that the next level should be skipped
                // cout<<i<<endl;
            } else {
                // Add the children to the queue for the next level
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }

        // If the node was found, the next level will be the cousins' level
        if (found) {
            while (!q.empty()) {
                cout << q.front()->data << " ";
                q.pop();
            }
            cout << endl;
        }
    }

    if (!found) {
        cout << "No cousins" << endl;
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    printCousins(root, root->left->left);  // Output: 6 7

    return 0;
}


