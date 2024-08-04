//the top should contain the largest element and the last should contain smallest element
// 5 -2 9 -7 3
// Sample Output 
// 9 5 3 -2 -7
#include <bits/stdc++.h> 
void insertSorted(stack<int> &s1,int x){ //T(n) =  O(n^2) ,S(n) =  O(n)
	if(s1.empty() || x>s1.top()){
		s1.push(x);
	}
	else{
		int t=s1.top();
		s1.pop();
		insertSorted(s1,x);
		s1.push(t);
	}
}
void sortStack(stack<int> &s1)
{
	// Write your code here
	if(!s1.empty()){
		int x = s1.top();
		s1.pop();
		sortStack(s1);
		insertSorted(s1,x);
	}

}
//solved using loop
while(!stk.isEmpty()){
        int x=stk.pop();
        if(stk1.isEmpty()){
         stk1.push(x);
        }
    else{
        while(x<=stk1.Top() && !stk1.isEmpty()){
            stk2.push(stk1.pop());
        }
        stk1.push(x);
        while(!stk2.isEmpty()){
            stk1.push(stk2.pop());
        }
    }

std::stack<int> tmpStack; //reduce one stack by pusing again into the original stack
    while (!input.empty()) {
        int tmp = input.top();
        input.pop();
        while (!tmpStack.empty() && tmpStack.top() < tmp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
