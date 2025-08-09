// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> bit;
        ListNode* t=head;
        int i=0;
        while(t!=nullptr){
            bit.push_back(t->val);
            t=t->next;
            i++;
        }
        int n=bit.size();
        int bin=0;
        for(int i=n-1;i>=0;i--){
            if(bit[i]){
                bin+=pow(2,n-i-1);
            }
        }
        return bin;
    }
};
class Solution {
public:
    int getDecimalValue(ListNode* head) { //using left shift and OR operator
        int num = 0;
        while (head != nullptr) {
            num = (num << 1) | head->val;
            head = head->next;
        }
        return num;
    }
};
