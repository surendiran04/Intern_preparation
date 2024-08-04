You are given the head of a linked list, which contains a series of integers separated by 0s. The beginning and end of the linked list will have Node.val == 0.
For every two consecutive 0s, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. 
The modified list should not contain any 0s.
Return the head of the modified linked list.

  Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
  
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       if(!head->next) return nullptr;
    
    //fetch sum from current 0 to next 0
    ListNode* ptr= head->next;
    int sum=0;
    while(ptr->val!=0) sum+= ptr->val, ptr=ptr->next;
    
    //assign sum on the first node between nodes having value 0.
    head->next->val= sum;
    
    //call and get the answer and connect the answer to next of head->next
    head->next->next= mergeNodes(ptr);
    
    //return head->next..=> new head
    return head->next;
    }
};
