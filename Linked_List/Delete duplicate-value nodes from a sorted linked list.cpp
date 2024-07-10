Input:1 2 2 2 3 3 4
ouput:1 2 3 4  
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
   SinglyLinkedListNode* p = llist;
    while (p && p->next) {
        if (p->data == p->next->data) {
            SinglyLinkedListNode* temp = p->next;
            p->next = temp->next;
            delete temp; 
        } else {
            p = p->next;
        }
    }
    return llist;
    
}
