// Input: head = [1,2,3,3,4,4,5]  if a node is repeating then delete the node nd return the new set of nodes
// Output: [1,2,5]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }

            if (prev->next != curr) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

class Solution { //using map approach - creating new nodes
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode *p = head;
        while (p) {
            mp[p->val]++;
            p = p->next;
        }
        
        ListNode *head2 = nullptr, *tail = nullptr;
        for (auto &it : mp) {
            if (it.second == 1) {
                ListNode *node = new ListNode(it.first);
                if (!head2) {
                    head2 = node;
                    tail = head2;
                } else {
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
        return head2;
    }
};
