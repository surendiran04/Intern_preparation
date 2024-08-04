class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fastp = head;
    ListNode* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < n; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    ListNode* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
    }
};
