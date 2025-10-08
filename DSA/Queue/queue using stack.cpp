#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            // Transfer from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl; // 1
    cout << q.dequeue() << endl; // 2
    q.enqueue(4);
    cout << q.dequeue() << endl; // 3
    cout << q.dequeue() << endl; // 4
}


//use the operations of stack and implement q
sampleInput:
// STDIN   Function
// -----   --------
// 10      q = 10 (number of queries)
// 1 42    1st query, enqueue 42
// 2       dequeue front element
// 1 14    enqueue 42
// 3       print the front element
// 1 28    enqueue 28
// 3       print the front element
// 1 60    enqueue 60
// 1 78    enqueue 78
// 2       dequeue front element
// 2       dequeue front element
output:
14
14
  
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1,s2;
    
    void moves1tos2(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
   public:
    
     void enq(int x){
         s1.push(x);
     }
    
     void deq(){
         if(s2.empty()){
         moves1tos2();
         }
         
         if(!s2.empty()){
             s2.pop();
         }
     }
    
     int front(){
         if(s2.empty()){
         moves1tos2();
         }
         
         if(!s2.empty()){
             return s2.top();
         }
         
         return -1;
         
     }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin >> q;
    Queue queue;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queue.enq(x);
        } else if (type == 2) {
            queue.deq();
        } else if (type == 3) {
            cout << queue.front() << endl;
        }
    }
    return 0;
}
