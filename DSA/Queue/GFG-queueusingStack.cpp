#include <stack>

class MyQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (!stack2.empty()) {
            int top = stack2.top();
            stack2.pop();
            return top;
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int top = stack2.top();
            stack2.pop();
            return top;
        }
    }

    int peek() {
        if (!stack2.empty()) {
            return stack2.top();
        } else {
            return stack1.top();
        }
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

