# LeetCode #155: Min Stack

'''
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
'''

class MinStack:
    # @param x, an integer
    # @return an integer
    def __init__(self):
        self.s1 = []
        self.s2 = []
    
    def push(self, x):
        self.s1.append(x)
        if len(self.s2) == 0 or x < self.s2[-1]:
            self.s2.append(x)
        else:
            self.s2.append(self.s2[-1])

    # @return nothing
    def pop(self):
        if len(self.s1) != 0 and len(self.s2) != 0:
            self.s1.pop()
            self.s2.pop()
            

    # @return an integer
    def top(self):
        if len(self.s1) != 0:
            return self.s1[-1]
        return -1

    # @return an integer
    def getMin(self):
        if len(self.s2) != 0:
            return self.s2[-1]
        return -1
        