/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
 // 1---2---3---4---5---6--NULL
 //         |
 //         7---8---9---10--NULL
 //             |
 //             11--12--NULL
// ans : 1---2---3--7---8-- 11--12--9---10--4---5---6--NULL

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr){
            if(curr->child){
                Node* next=curr->next;
                Node* child=curr->child;
                child->prev=curr;
                curr->next=child;
                curr->child=nullptr;
                while(child->next) child=child->next;

                if(next) next->prev=child;
                child->next=next;
            }
            curr=curr->next;
        }
        return head;
    }
};
