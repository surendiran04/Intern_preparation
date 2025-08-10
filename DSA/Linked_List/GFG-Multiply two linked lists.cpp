// Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.
// Note: The output could be large take modulo 10^9+7.

// Examples :

// Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
// Output: 64

// Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
// Output: 1000

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        if (!first || !second) return 0;
        // code here
        long long mod=1000000007LL
        long long num1=0,num2=0;
        while(first || second){
            if(first){
                num1=((num1*10)%mod+first->data)%mod;
                first=first->next;
            }
            if(second){
                num2=((num2*10)%mod+second->data)%mod;
                second=second->next;
            }
        }
        return (num1*num2)%mod;
    }
};
