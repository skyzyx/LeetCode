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