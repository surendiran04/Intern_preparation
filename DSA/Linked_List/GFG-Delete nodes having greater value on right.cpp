// Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.
// Examples:
// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15->11->6->3
// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60

class Solution {
  public:
    Node* reverseList(Node *p){
        Node* r=NULL;
        Node* q=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    Node *compute(Node *head) {
        // your code goes here
        if(!head){
            return head;
        }
        head=reverseList(head);
        Node* curr=head;
        int maxval=curr->data;
        while(curr && curr->next){
            if(curr->next->data<maxval){
                Node* t=curr->next;
                curr->next=t->next;
                delete t;
            }else{
                curr=curr->next;
                maxval=curr->data;
            }
        }
        head=reverseList(head);
        return head;
        
    }
};
