struct compare {
    bool operator()(pair<int, ListNode*>& a, pair<int, ListNode*>& b) {
        return a.first > b.first;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,compare> minheap;
        for (int i = 0; i < n; i++) {
            if (lists[i] != nullptr) {
                minheap.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* t = head;

        while (!minheap.empty()) {
            ListNode* curr = minheap.top().second;
            minheap.pop();
            t->next = curr;
            t = t->next;

            if (curr->next != nullptr) {
                minheap.push({curr->next->val, curr->next});
            }
        }
        return head->next;
    }
};
