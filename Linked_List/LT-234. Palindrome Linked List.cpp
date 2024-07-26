class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *t=head;
        while(t){
            st.push(t->val);
            t=t->next;
        }
        t=head;
        while(t){
            if(t->val!=st.top()){
                return false;
            }
            t=t->next;
            st.pop();
        }
        return true;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) { //reversing from the middle

        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* t = reverseLL(slow->next);
        fast = head;
        while (t!=nullptr) {
            if(t->val!=fast->val){
                return false;
            }  
            t = t->next;
            fast=fast->next;
        }
        return true;
    }
private : 
    ListNode* reverseLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = head;
        ListNode *q = NULL, *r = NULL;
        while (p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
};
