//video - https://youtu.be/Of0HPkk3JgI?si=3YCQrdoBWrr6GWIL
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5] reverse group of k nodes and link
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* t=head;
        while(t){
            n++;
            t=t->next;
        }
        for(int i=0;i+k<=n;i+=k){
            head=reverseBetween(head,i+1,i+k);
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {  //reverse LL-2 Logic
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
        prev->next->next=p;
        prev->next=q;
        return dummy->next;
    }
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k<2){
            return head;
        }
        int len=0;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=dummy,*nex=dummy,*prev=dummy;
        while(curr->next!=nullptr){
            len++;
            curr=curr->next;
        }
        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            len-=k;
        }
        return dummy->next;
    }
     
};
