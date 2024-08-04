class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0 || head->next==nullptr){
            return head;
        }
        int len=length(head);
        k=k%len;
        ListNode* temp=head;
        while(k--){
           temp=rotateLL(temp);
        }
        return temp;
    }
private:
   ListNode* rotateLL(ListNode* head){
    ListNode* t=head;
    while(t->next->next!=nullptr){
        t=t->next;
    }
    ListNode *p=t->next;
    t->next=nullptr;
    p->next=head;
    return p;
   }
   int length(ListNode* t){
    int cnt=0;
    while(t){
        t=t->next;
        cnt++;
    }
    return cnt;
   }       
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0 || head->next==nullptr){
            return head;
        }
        ListNode* t=head;
        int len=1;
        while(t->next!=nullptr){
        t=t->next;
        len++;
        }
        t->next=head; //make circular links
        k=k%len;
        int end=len-k;
        while(end--){ //finding where cut the link ie,making NULL
           t=t->next;
        }
        head=t->next;
        t->next=nullptr;
        return head;
    }     
};
