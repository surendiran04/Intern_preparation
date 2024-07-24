class Solution {
public:
    void deleteNode(ListNode* node){ //To delete a node we need to change it's previous node->next=node->next->next ,here they haven't gave the previous node
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;    
    }
};
