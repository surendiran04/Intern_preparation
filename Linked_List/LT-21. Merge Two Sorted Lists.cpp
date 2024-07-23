class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)
            return list2;
        if(list2==nullptr){
            return list1;
        }
        ListNode* head = nullptr;
        ListNode* last=nullptr;
        if(list1->val<list2->val){
            head=list1;
            last=list1;
            list1=list1->next;
            head->next=NULL;
        }
        else{
            head=list2;
            last=list2;
            list2=list2->next;
            head->next=NULL;
        }
        while(list1 && list2){
            if(list1->val<list2->val){
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=NULL;
            }
            else{
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=NULL;
            }
        }
        if(list1)
            last->next=list1;
        if(list2)
            last->next=list2; 
        return head;       
    }
};
