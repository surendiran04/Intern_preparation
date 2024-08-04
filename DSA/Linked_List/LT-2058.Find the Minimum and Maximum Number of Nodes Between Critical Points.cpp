A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance 
between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. 
If there are fewer than two critical points, return [-1, -1].

Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {  //here talking above distance so index starts from 1
        vector<int> result(2, -1);
        int prev_critical_ind = -1, first_critical_ind = -1;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int cur_ind = 1;

        while (cur->next != nullptr) {
            if ((cur->val > prev->val && cur->val > cur->next->val) || (cur->val < prev->val && cur->val < cur->next->val)) {
                if (prev_critical_ind != -1) {
                    result[0] = (result[0] == -1) ? cur_ind - prev_critical_ind : min(result[0], cur_ind - prev_critical_ind); //min distance bw nodes
                } else {
                    first_critical_ind = cur_ind;  //intial critical index
                }
                prev_critical_ind = cur_ind;
            }
            prev = cur;
            cur = cur->next;
            cur_ind++;
        }

        if (prev_critical_ind != -1 && prev_critical_ind != first_critical_ind) {
            result[1] = prev_critical_ind - first_critical_ind;  //max distance bw nodes
        }

        return result;
    }
};
