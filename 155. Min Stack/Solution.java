class MinStack {
    private Stack<Integer> mainS;
    private Stack<Integer> minS;
    
    public MinStack() {
        mainS = new Stack<Integer>();
        minS = new Stack<Integer>();
    }
    
    public void push(int x) {
        mainS.push(x);
        if (minS.empty() || x < minS.peek())
            minS.push(x);
        else
            minS.push(minS.peek());
    }

    public void pop() {
        if (!mainS.empty()) {
            minS.pop();
            mainS.pop();
        }
    }

    public int top() {
        if (!mainS.empty())
            return mainS.peek();
        return -1;    
    }

    public int getMin() {
        if (!minS.empty())
            return minS.peek();
        return -1;
    }
}
