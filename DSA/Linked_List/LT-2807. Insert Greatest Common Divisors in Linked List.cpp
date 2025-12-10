class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p=head;
        while(p->next!=nullptr){
            int x=gcd(p->val,p->next->val);
            ListNode* t=new ListNode(x);
            ListNode* temp=p->next;
            p->next=t;
            t->next=temp;
            p=temp;
        }
        return head;
    }
    int gcd(int a,int b){
        for(int i=min(a,b);i>=1;i--){
            if(a%i==0 && b%i==0){
                return i;
            }
        }
        return 1;
    }
    int GCD(int a,int b){ //TC:log(min(a,b))
        if(b==0){
            return a;
        }
        return GCD(b,a%b);
    }
};
