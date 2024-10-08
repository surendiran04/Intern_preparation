class Solution {
public:
    ListNode *detectCycle(ListNode *head) { //also use hashmap ans hash the entire List if the listNode if the List exist in the map then then we an detect the cycle
        if(head==nullptr || head->next==nullptr){
            return NULL;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode* entry=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return NULL; 
    }
};
