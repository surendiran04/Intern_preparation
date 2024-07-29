// Input: head = [1,1,2]
// Output: [1,2]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
     if (head == NULL || head->next==NULL) {
            return head; // Empty list
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL){
            if(fast->val==slow->val){
                slow->next=fast->next;
                delete fast;
                fast=slow->next;
            }
            else{
                slow=slow->next;
                fast=fast->next;
            }
        }
        return head;
    }
};
