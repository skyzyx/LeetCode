// LeetCode #225: Implement Stack using Queues

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
*/

class Stack {
private:
    queue<int> que;
    
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);    
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = que.size();
        while (size != 1) {
            que.push(que.front());
            que.pop();
            size--;
        }
        que.pop();
    }

    // Get the top element.
    int top() {
        int size = que.size();
        while (size != 1) {
            que.push(que.front());
            que.pop();
            size--;
        }
        
        int top = que.front();
        que.pop();
        que.push(top);
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty() == true;
    }
};