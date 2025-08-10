// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* t=res;
        int carry=0;
        stack<int> st1,st2;
        while(list1){
            st1.push(list1->val);
            list1=list1->next;
        }
         while(list2){
            st2.push(list2->val);
            list2=list2->next;
        }
        while(!st1.empty() || !st2.empty() || carry){
            int sum=0;
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            t->next=node;
            t=t->next;
        }
        res=reverseList(res->next);
        return res;
    }
    ListNode* reverseList(ListNode *p){
        ListNode* r=NULL;
        ListNode* q=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
};
