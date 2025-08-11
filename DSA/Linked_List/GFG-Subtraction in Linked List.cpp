#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Utility to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Remove leading zeros
Node* removeLeadingZeros(Node* head) {
    while (head && head->data == 0 && head->next) {
        head = head->next;
    }
    return head;
}

// Compare two lists of equal length
bool isGreaterOrEqual(Node* l1, Node* l2) {
    while (l1 && l2) {
        if (l1->data > l2->data) return true;
        if (l1->data < l2->data) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true; // they are equal
}

// Get length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* subtractLinkedLists(Node* l1, Node* l2) {
    // Remove leading zeros
    l1 = removeLeadingZeros(l1);
    l2 = removeLeadingZeros(l2);

    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Ensure l1 is bigger
    if (len1 < len2 || (len1 == len2 && !isGreaterOrEqual(l1, l2))) {
        swap(l1, l2);
    }

    // Reverse both lists for easy subtraction
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node* dummy = new Node(-1);
    Node* tail = dummy;
    int borrow = 0;

    while (l1) {
        int val1 = l1->data - borrow;
        int val2 = (l2 ? l2->data : 0);

        if (val1 < val2) {
            val1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int diff = val1 - val2;
        tail->next = new Node(diff);
        tail = tail->next;

        l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    // Reverse result back
    Node* result = reverseList(dummy->next);
    result = removeLeadingZeros(result);

    return result;
}

// Helper to print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "\n";
}

// Example usage
int main() {
    // Example 1: 1->0->0 - 1->2
    Node* l1 = new Node(1);
    l1->next = new Node(0);
    l1->next->next = new Node(0);

    Node* l2 = new Node(1);
    l2->next = new Node(2);

    Node* res = subtractLinkedLists(l1, l2);
    printList(res); // Output: 8->8

    // Example 2: 6->3 - 7->1->0
    Node* a = new Node(6);
    a->next = new Node(3);

    Node* b = new Node(7);
    b->next = new Node(1);
    b->next->next = new Node(0);

    res = subtractLinkedLists(a, b);
    printList(res); // Output: 6->4->7

    return 0;
}
