#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void createCycle(int pos) {
        if (pos == -1) return; // No cycle

        Node* temp = head;
        Node* cycleNode = NULL;
        int index = 0;

        while (temp->next) {
            if (index == pos) {
                cycleNode = temp;
            }
            temp = temp->next;
            index++;
        }
        temp->next = cycleNode; // Create cycle
    }

    bool hasCycle() {
        Node *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        LinkedList* l = new LinkedList();
        int n;
        cin >> n; // Number of nodes

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            l->insert(val);
        }

        int pos;
        cin >> pos; // Position where cycle should be created (-1 if no cycle)
        l->createCycle(pos);

        cout << (l->hasCycle() ? "YES" : "NO") << endl;
    }

    return 0;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
