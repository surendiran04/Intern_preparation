// Problem Statement
// You are given a linked list head of size N. Your task is to remove the last occurrence of all the elements in the linked list.
// Note: If there is an element with a  frequency 1 in the list, remove that too.
// Input Format
// The first line contains a single integer N. 
// The second line contains N space-separated integers representing the linked list.

// Output Format
// Print the linked list after removing the last occurrence of all the elements in it.

// Constraints
// 0 <= N <= 10^5
// 1 <= val <= 10^4

// Sample Testcase 0
// Testcase Input
// 3
// 1 2 2
// Testcase Output
// 2
// Explanation
// The occurrence of 1 will be deleted as it’s a single-frequency element.


// The last 2 will get deleted. So, the resultant list will be {2} only.

// Sample Testcase 1
// Testcase Input
// 2
// 1 2
// Testcase Output
 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* remove_last_occurrences(ListNode* head) {
    // Write your logic here to remove the last occurrence of all elements in the linked list.
    if(!head){
        return nullptr;
    }
    unordered_map<int,ListNode*> map;
    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* p=dummy;
    ListNode * t = head;
    while(t){
        map[t->val]=t;
        t=t->next;
    }
    t=dummy->next; //it is stable don't use head
    while(t){
        if(map[t->val]==t){
            p->next=t->next;
            delete t;
            t=p->next;
        }else{
            p=t;
            t=t->next; 
        }
        
    }
    return dummy->next;
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << endl;
        return 0;
    }

    ListNode* head = NULL;
    ListNode* current = NULL;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ListNode* new_node = new ListNode(value);
        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    // Call user logic function
    ListNode* modified_head = remove_last_occurrences(head);

    // Print the modified linked list
    print_linked_list(modified_head);

    return 0;
}
