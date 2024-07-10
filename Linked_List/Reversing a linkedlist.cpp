Input:1 2 3 4 5 NULL
Output:5 4 3 2 1 NULL  
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* p=llist;
    SinglyLinkedListNode* q=nullptr;
    SinglyLinkedListNode* r=nullptr;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}
