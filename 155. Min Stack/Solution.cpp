// LeetCode #155: Min Stack

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    stack<int> main;
    stack<int> min;
    
    void push(int x) {
        main.push(x);
        if (min.empty() || x < min.top())
            min.push(x);
        else
            min.push(min.top());
    }

    void pop() {
        if (!main.empty() && !min.empty()) {
            main.pop();
            min.pop();
        }
    }

    int top() {
        if (!main.empty())
            return main.top();
        return -1;
    }

    int getMin() {
        if (!min.empty())
            return min.top();
        return -1;
    }
};