class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* ptr=head;
        vector<int>st;
        while(ptr != NULL)
        {
            st.push_back(ptr->val);
            ptr=ptr->next;

        }
        sort(st.begin(),st.end());
        ptr=head;
        int k=0;
        while(ptr != NULL)
        {
            ptr->val=st[k++];
            ptr=ptr->next;

        }
        return head;
    }
};
