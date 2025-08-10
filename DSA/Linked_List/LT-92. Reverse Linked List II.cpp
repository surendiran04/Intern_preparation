// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* dummy=new ListNode(-1);
       ListNode* prev=dummy;
       dummy->next=head;
       for(int i=1;i<left;i++){
        prev=prev->next;
       }
        ListNode*p=prev->next;
        ListNode* q=nullptr;
        ListNode* r=nullptr;
        for(int i=0;i<=(right-left);i++){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        prev->next->next=p; //2->next=5
        prev->next=q;       //1->next=4
        return dummy->next;
    }
};
