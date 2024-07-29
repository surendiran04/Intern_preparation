class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return NULL;
        }
        ListNode* dummy=new ListNode(0,head);
        ListNode* p=head;
        ListNode* q=dummy;
        while(p){
            if(p->val==val){
                q->next=p->next;
                delete p;
                p=q->next;
            }
            else{
                q=q->next;
                p=p->next;
            }
        }
        return dummy->next;
    }
};
