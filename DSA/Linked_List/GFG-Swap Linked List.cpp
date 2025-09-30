// C++ program to swaps the nodes of linked list rather
// than swapping the data from the nodes.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  	Node(int x) {
      	data = x;
      	next = nullptr;
    }
};

// Function to swap nodes x and y in linked list by
// changing links and return the updated head 
Node* swapNodes(Node* head, int x, int y) {
  
    // Nothing to do if x and y are same
    if (x == y)
        return head;

    Node *prevX = nullptr, *currX = nullptr;
    Node *prevY = nullptr, *currY = nullptr;
    Node *prev = nullptr, *curr = head;

    // Single loop to find both x and y
    while (curr != nullptr) {
        if (curr->data == x) {
            prevX = prev;
            currX = curr;
        } else if (curr->data == y) {
            prevY = prev;
            currY = curr;
        }
        prev = curr;
        curr = curr->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == nullptr || currY == nullptr)
        return head;

    // If x is not head of the linked list
    if (prevX != nullptr)
        prevX->next = currY;
    else // Else make y the new head
        head = currY;

    // If y is not head of the linked list
    if (prevY != nullptr)
        prevY->next = currX;
    else 
      	// Else make x the new head
        head = currX;

    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return head;
}

void print(Node* curr) {
  
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
  
    // Constructed linked list:
    // 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = swapNodes(head, 4, 3);
    print(head);

    return 0;
}
